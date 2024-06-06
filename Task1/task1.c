/*
Задание 1. Биномиальный коэффициент

Реализовать программу 1-го практического задания с помощью
биномиального коэффициента.
Данные на вход: Два целых числа N и M
Данные на выход: Одно целое число – количество вариантов

Пример №1
Данные на вход:
10 5
Данные на выход: 252
Пример №2
Данные на вход:
35 5
Данные на выход: 324632
Пример №3
Данные на вход:
40 10
Данные на выход: 847660528
*/
#include <stdio.h>

long long binomial_coefficient(int n, int k)
{
	if (k > n)
	{
		printf("Error: k cannot be greater than n.\n");
		return -1;
	}

	long long result = 1;
	for (int i = 1; i <= k; i++)
	{
		result = result * (n - i + 1) / i;
	}
	return result;
}

int main()
{
	int N, M;
	printf("Enter N and M (positive integers): ");
	scanf("%d %d", &N, &M);

	if (N < 0 || M < 0)
	{
		printf("Error: N and M must be positive integers.\n");
		return -1;
	}

	long long variants = binomial_coefficient(N, M);
	printf("The number of ways to choose: %lld\n", variants);
	return 0;
}