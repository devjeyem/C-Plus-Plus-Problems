#include <stdio.h>

int is_prime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int sum_of_digits(long long number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

long long D(int n)
{
    int count_primes = 0;
    long long current_number = 1;

    while (count_primes < n)
    {
        if (is_prime(sum_of_digits(current_number)))
        {
            count_primes++;
        }
        current_number++;
    }

    return current_number - 1;
}

int main()
{
    long long result = D(600851475143); // 10^16
    printf("%lld\n", result);

    return 0;
}
