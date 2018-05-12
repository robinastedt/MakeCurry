/*
Author: Robin Åstedt <robin.astedt@gmail.com>
GitHub: https://github.com/robinastedt/MakeCurry
*/

#ifndef _MAKE_CURRY_H_
#define _MAKE_CURRY_H_

#include <memory>
#include <functional>

namespace make_curry_util {

    template<typename FUNC>
    struct curry_container;

    // Specialiaztion for base case (one argument -> already curried)
    template<typename RETURN, typename FIRST>
    struct curry_container<std::function<RETURN(FIRST)>>
    {
        // Single argument functions are already curried
        using curried_t = std::function<RETURN(FIRST)>;

        // Stores the curried function upon initialization
        const curried_t curried_func;
        curry_container(curried_t func) : curried_func(func) {}
    };

    // Specialization recursive
    template<typename RETURN, typename FIRST, typename... REST>
    struct curry_container<std::function<RETURN(FIRST,REST...)>>
    {
        // Recursive type definition of nested functions
        using curried_t = std::function<struct curry_container<std::function<RETURN(REST...)>>::curried_t(FIRST)>;

        // Constructs curried function and stores it
        const curried_t curried_func;
        curry_container(std::function<RETURN(FIRST, REST...)> func) 
        : curried_func(
            // Curried function declaration
            [func](const FIRST& first) -> auto
            {
                // Nested curry_container object
                const auto recursive_curry = curry_container<std::function<RETURN(REST...)>>(
                    //Pass function that takes the rest of the arguments to be curried by the container
                    [first, func](const REST&... rest) -> auto
                    {
                        return func(first, rest...);
                    }
                );
                // Extract the nested curry
                return recursive_curry.curried_func;
            }) {}
    };
}


// Implementation for lambda expressions
template<typename RETURN, typename... ARGS>
auto make_curry(const std::function<RETURN(ARGS...)> func)
{
    // Build curry container
    const auto container = make_curry_util::curry_container<std::function<RETURN(ARGS...)>>(func);
    // Extract curried function
    return container.curried_func;
}

// Implementation for function pointers
template<typename RETURN, typename... ARGS>
auto make_curry(RETURN(*const func)(ARGS...))
{
    // Build curry container
    const auto container = make_curry_util::curry_container<std::function<RETURN(ARGS...)>>(func);
    // Extract curried function
    return container.curried_func;
}

#endif