#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int power = 1000;
    const int base = 2;
    int digits[500] = {0}; // Enough space for the digits of 2^1000

    digits[0] = 1; // Start with 2^0 = 1
    int carry = 0;

    for (int i = 0; i < power; ++i) 
    {
        for (int j = 0; j < 350; ++j) 
        {
            digits[j] = digits[j] * base + carry;
            carry = digits[j] / 10;
            digits[j] %= 10;
        }
    }

    // Calculate the sum of digits
    int sum = 0;
    for (int i = 0; i < 350; ++i) 
    {
        sum += digits[i];
    }

    cout << "Sum of digits of 2^1000: " << sum << endl;

    return 0;
}
