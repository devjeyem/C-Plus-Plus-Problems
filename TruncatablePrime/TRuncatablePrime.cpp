#include <iostream>
#include <string>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
        i += 6;
    }
    return true;
}

bool is_truncatable_prime(int n) {
    string str_n = to_string(n);
    for (int i = 1; i < str_n.length(); ++i) {
        if (!is_prime(stoi(str_n.substr(i))) || !is_prime(stoi(str_n.substr(0, i)))) {
            return false;
        }
    }
    return true;
}

int main() {
    int truncatable_primes[11];
    int count = 0;
    int num = 11;
    while (count < 11) {
        if (is_prime(num) && is_truncatable_prime(num)) {
            truncatable_primes[count] = num;
            ++count;
        }
        num += 2; // Skip even numbers since they can't be prime
    }
    
    int sum = 0;
    for (int i = 0; i < 11; ++i) {
        sum += truncatable_primes[i];
    }

    cout << "The first 11 truncatable primes are: ";
    for (int i = 0; i < 11; ++i) {
        cout << truncatable_primes[i] << " ";
    }
    cout << endl;
    cout << "Their sum is: " << sum << endl;

    return 0;
}
