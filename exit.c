#include "shell.h"

/**
 * exit_shell - this will exit the shell
 *
 * @datash: the relevant data (status and args)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int digit;
	int len;
	int big_num;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		digit = _isdigit(datash->args[1]);
		len = _strlen(datash->args[1]);
		big_num = ustatus > (unsigned int)INT_MAX;
		if (!digit || len > 10 || big_num)
		{
			_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}
/**
 * exec_line - finding builtins and commands
 *
 * @datash: the relevant (args)
 * Return: 1 on success.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
