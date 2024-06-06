/*
Задание 2. Обратная польская запись

Написать алгоритм перевода из инфиксной записи в обратную польскую. Для
его реализации нужны данные по приоритетам операций. Реализовать
алгоритм, используя побитовые операции (&, |, ^).

Пример №1
Данные на вход:
( 3 & 5 ) ^ 4 | 9
Данные на выход: 3 5 & 4 ^ 9 |
Пример №2
Данные на вход:
8 ^ 2 & 5 | ( 6 & 1 )
Данные на выход: 8 2 5 & ^ 6 1 & |
 */
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 255
#define STACK_SIZE 255

char oper[STACK_SIZE] = {0};
int oend = 0;

void push(char v)
{
	oper[oend++] = v;
}

char pop()
{
	if (oend <= 0 || oend >= STACK_SIZE)
	{
		printf("Stack is empty\n");
		exit(1);
	}
	return oper[--oend];
}

_Bool emptyStack()
{
	return oend == 0;
}

_Bool isOperator(char c)
{
	return c == '&' || c == '^' || c == '|';
}

int priority(char c)
{
	if (c == '&')
	{
		return 3;
	}
	else if (c == '^')
	{
		return 2;
	}
	else if (c == '|')
	{
		return 1;
	}

	return 0;
}

int main()
{
	char c;
	int pos = 0;
	char answer[BUFFER_SIZE] = {0};
	printf("Input infix string: ");
	char str[1000];

	int len = 0;
	while ((c = getchar()) != '\n')
	{
		str[len++] = c;
	}
	str[len] = '\0';

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			int number, size = 0;
			for (number = 0; str[i] >= '0' && str[i] <= '9'; i++, size++)
			{
				number = number * 10 + (str[i] - '0');
			}
			sprintf(answer + pos, "%d", number);
			pos += size + 1;
		}
		else
		{
			if (i >= len)
			{
				break;
			}
			c = str[i];
			if (isOperator(c))
			{
				while (!emptyStack())
				{
					char top = pop();
					if (priority(top) >= priority(c))
					{
						sprintf(answer + pos, "%c", top);
						pos += 2;
					}
					else
					{
						push(top);
						break;
					}
				}
				push(c);
			}
			else if (c == '(')
			{
				push(c);
			}
			else if (c == ')')
			{
				while ((c = pop()) != '(')
				{
					sprintf(answer + pos, "%c", c);
					pos += 2;
				}
			}
		}
	}

	while (!emptyStack())
	{
		char c = pop();
		sprintf(answer + pos, "%c", c);
		pos += 2;
	}
	printf("Postfix notation: ");
	for (int i = 0; i < pos; i++)
	{
		printf("%c", answer[i]);
	}

	return 0;
}
