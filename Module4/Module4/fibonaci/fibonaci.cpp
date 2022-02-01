// fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

const int MAX_ENTRIES = 93;
/// <summary>
/// return the n fibonacii number defined by
/// f(n) = f(n-1) + f(n-2)                    
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
__int64 fibonacci(unsigned int n) {
    __int64 result = { 0 };
    if (n == 0 || n == 1) {
        result = 1;
    }
    else {
        result = fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    return result;
}
void testRecursiveFibonacci() {
    std::cout << "recursive fibonacii sequence!\n";
    for (size_t i = 0; i < MAX_ENTRIES; i++) {
        std::cout << i << ":" << fibonacci(i) << std::endl;
    }
}
void printFibonacii(__int64 n, __int64 fn)
{
    std::cout << n << ":" << fn << std::endl;
}
void testEfficientFibonacii() {
    std::cout << "efficient fibonacii sequence!\n";
    __int64 f0 = 1;
    __int64 f1 = 1;
    __int64 f2 = {};
    printFibonacii(0, f0);
    printFibonacii(1, f1);
    for (size_t i = 2; i < MAX_ENTRIES; i++) {
        __int64 f2 = f0 + f1;
        printFibonacii(i, f2);
        f0 = f1;
        f1 = f2;
    }
}
int main() {
    testEfficientFibonacii();
    testRecursiveFibonacci();
}
