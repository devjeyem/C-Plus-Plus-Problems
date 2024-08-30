#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<int>& result, int x) {
    int carry = 0;
    for (int i = 0; i < result.size(); ++i) {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

int sumOfDigitsFactorial(int n) {
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; ++i) {
        multiply(result, i);
    }

    int sum = 0;
    for (int digit : result) {
        sum += digit;
    }

    return sum;
}

int main() {
    int num = 100;
    int sum = sumOfDigitsFactorial(num);
    cout << "Sum of the digits of the factorial of " << num << " is: " << sum << endl;
    return 0;
}
