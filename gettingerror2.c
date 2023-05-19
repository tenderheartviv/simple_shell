#include "shell.h"

/**
 * er_env - this is error message for env in get_env.
 * @datash: the relevant data (counter, arguments)
 * Return:this is error message.
 */
char *er_env(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;
	char *msges;

	ver_str = _itoa(datash->counter);
	msges = ": Unable to add/remove from environment\n";
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(msges) + 4;
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
	_strcat(err, msges);
	_strcat(err, "\0");
	free(ver_str);

	return (err);
}
/**
 * er_path_126 - the error message for path and failure denied permission.
 * @datash: the relevant  data (counter, arguments).
 *
 * Return: This the error string.
 */
char *er_path_126(data_shell *datash)
{
	int len;
	char *ver_str;
	char *err;

	ver_str = _itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 24;
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
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}
