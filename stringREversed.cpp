#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char* strRev(char* str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

int main ()
{
    char str[] = "world";
    cout << strRev(str);
}