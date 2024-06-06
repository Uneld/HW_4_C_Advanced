/*
Задание 3. Префикс и суффикс

Реализовать программу 3-го практического задания более эффективным
способом со сложностью О(n) (см. код в лекции).

Пример №1
Данные на вход:
don't_panic
nick_is_a_mastodon
Данные на выход: 3
Пример №2
Данные на вход:
monty_python
python_has_list_comprehensions
Данные на выход: 6
*/
#include <windows.h>
#include <stdio.h>
#include <string.h>

void computeLPSArray(char *str, int M, int lps[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int findMaximumPrefixSuffix(char *str)
{
    int M = strlen(str);
    int lps[M];
    computeLPSArray(str, M, lps);

    return lps[M - 1];
}

void fun(char *str)
{
    // Do some work here
    for (int i = 0; i < 10; i++)
    {
        findMaximumPrefixSuffix(str);
    }
}

int main()
{
    char s1[105], s2[105];
    printf("Enter two strings:\n");
    scanf("%104s", s1);
    scanf("%104s", s2);
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);
    char *stcat = strcat(s1, s2);
    double averTime = 0;
    const int COUNT_TEST = 10;

    for (size_t i = 0; i < COUNT_TEST; i++)
    {

        QueryPerformanceCounter(&start);
        fun(stcat);
        QueryPerformanceCounter(&end);
        double time_taken = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 1000000;
        averTime = averTime + time_taken;
        printf("Time taken by program is : %f microseconds\n", time_taken);
    }

    averTime = averTime / COUNT_TEST;
    printf("Average time taken by program is : %f microseconds\n", averTime);
    printf("Max_len %d\n", findMaximumPrefixSuffix(stcat));
    return 0;
}
