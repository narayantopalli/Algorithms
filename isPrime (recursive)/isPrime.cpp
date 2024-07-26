#include <iostream>
#include <string>
#include "isPrime.hpp"

int main() {
    long long num;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::string res = (isPrime(num)) ? " is prime!\n": " is not prime!\n";
    std::cout << num << res;
    return 0;
}
