## Make Curry
Utility function for making curry out of multiple argument functions!

When programming in C++, do you often find yourself missing the magic of Haskell's naturally curried syntax? Then this is for you! Avoid declaring functions using the mess that is nested lambda expressions and simply use the normal C++ syntax to declare your functions like a sane person and make_curry will translate it into a curryingable function for you!

## Why?
Mostly because I was bored, and as a fun exercise to learn C++.

## Example usage
```cpp

#include <iostream>
#include "MakeCurry.h"

int testFunc1(int x) {
    return x;
}

int testFunc2(int x, int y) {
    return x + y;
}

int testFunc3(int x, int y, int z) {
    return x + y + z;
}

int testFunc4(int x, int y, int z, int w) {
    return x + y + z + w;
}

int main(int argc, char** argv) {

    auto curryTest1 = make_curry(testFunc1);
    std::cout << curryTest1(1) << std::endl;

    auto curryTest2 = make_curry(testFunc2);
    std::cout << curryTest2(1)(1) << std::endl;

    auto curryTest3 = make_curry(testFunc3);
    std::cout << curryTest3(1)(1)(1) << std::endl;

    auto curryTest4 = make_curry(testFunc4);
    std::cout << curryTest4(1)(1)(1)(1) << std::endl;
}
```