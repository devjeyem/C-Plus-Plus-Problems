#include <string.h>
#include <stdio.h>

char *strrev(char *str)
{
    if (!str) return str;

    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}

int main()
{
    char str1[] = "world";
    printf("%s\n", strrev(str1));  // Outputs: 'dlrow'

    char str2[] = "word";
    printf("%s\n", strrev(str2));  // Outputs: 'drow'

    return 0;
}
