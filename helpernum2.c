#include "shell.h"

/**
 * get_len - get the lenght of a number.
 * @n: it is the type int number.
 * Return: Lenght of a number.
 */
int get_len(int n)
{
	unsigned int num1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		num1 = n * -1;
	}
	else
	{
		num1 = n;
	}
	while (num1 > 9)
	{
		lenght++;
		num1 = num1 / 10;
	}

	return (lenght);
}
/**
 * _itoa - Function converts int to string.
 * @n: it is a type int number
 * Return: String.
 */
char *_itoa(int n)
{
	unsigned int num1;
	int len = get_len(n);
	char *buff;

	buff = malloc(sizeof(char) * (len + 1));
	if (buff == 0)
		return (NULL);

	*(buff + len) = '\0';

	if (n < 0)
	{
		num1 = n * -1;
		buff[0] = '-';
	}
	else
	{
		num1 = n;
	}

	len--;
	do {
		*(buff + len) = (num1 % 10) + '0';
		num1 = num1 / 10;
		len--;
	}
	while (num1 > 0)
		;
	return (buff);
}
/**
 * read_line - it reads the input string.
 *
 * @i_eof: this is the return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *enter = NULL;
	size_t size = 0;

	*i_eof = getline(&enter, &size, stdin);

	return (enter);
}
