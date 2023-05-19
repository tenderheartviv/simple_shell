#include "shell.h"

/**
 * concat_cd - the function that concatenates the message for cd error
 *
 * @datash: the data relevant (directory)
 * @msg: the message to print
 * @error: the output message
 * @ver_str: the counter lines
 * Return: this will display error message
 */
char *concat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * er_cd - this is the error message for cd command in get_cd
 * @datash: the relevant data (directory)
 * Return: This displays error message
 */
char *er_cd(data_shell *datash)
{
	int len, len_id;
	char *err, *ver_str, *msges;

	ver_str = _itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msges = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msges = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msges) + len_id + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = concat_cd(datash, msges, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * er_not_found - the generic error message for command not found
 * @datash:the relevant data (counter, arguments)
 * Return: This display error message
 */
char *er_not_found(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = _itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * er_exit - this is the generic error message for exit in get_exit
 * @datash: the relevant data (counter, arguments)
 *
 * Return: This display error message
 */
char *er_exit(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = _itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
