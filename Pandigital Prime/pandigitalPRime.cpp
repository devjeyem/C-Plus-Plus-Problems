#include <iostream>
#include <algorithm>
#include <string>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    int largestPandigitalPrime = 0;

    // Start from the largest 7-digit pandigital number and work downwards
    for (int i = 7654321; i >= 1234567; i--) {
        std::string number = std::to_string(i);
        if (std::all_of(number.begin(), number.end(), [](char c) { return number.find(c) == number.rfind(c); })) {
            if (isPrime(i)) {
                largestPandigitalPrime = i;
                break;
            }
        }
    }

    std::cout << "The largest pandigital prime is: " << largestPandigitalPrime << std::endl;

    return 0;
}
