
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

