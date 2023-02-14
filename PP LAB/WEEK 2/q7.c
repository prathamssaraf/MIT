#include <stdio.h>
#include <omp.h>
#include <ctype.h>

#define SIZE 5

int main()
{
    int i;
    char str[SIZE] = {'H', 'e', 'L', 'L', 'o'};

    #pragma omp parallel for
    for (i = 0; i < SIZE; i++)
    {
        int id = omp_get_thread_num();
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else
        {
            str[i] = toupper(str[i]);
        }
        printf("Thread %d toggled character %c\n", id, str[i]);
    }

    printf("Toggled string: %s\n", str);

    return 0;
}

