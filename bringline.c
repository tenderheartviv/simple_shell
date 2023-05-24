#include "shell.h"

/**
 * bring_line - it assigns the line var for get_line
 * @lineptr: it is the Buffer that stores the input str
 * @buffer: str that is been called to line
 * @n: Size of line
 * @j: it is size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - Read inpt from stream
 * @lineptr: buffer that stores the input
 * @n: this is the size of lineptr
 * @stream: it stream to read from
 * Return: number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buff;
	char th = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (th != '\n')
	{
		i = read(STDIN_FILENO, &th, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buff);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buff = _realloc(buff, input, input + 1);
		buff[input] = th;
		input++;
	}
	buff[input] = '\0';
	bring_line(lineptr, n, buff, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
