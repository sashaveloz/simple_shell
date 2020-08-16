#include "holberton.h"

/**
 * main - Principal file for shell
 *@ac: Argument count
 *@av: Argument value
 *@env: Environment
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	char *lineptr = NULL, **arg = NULL;
	int nprocs = 0, _exit = 0;
	(void)ac;

	while (1)
	{
		lineptr = prompt();
		if (lineptr)
		{
			nprocs++;
			arg = split(lineptr);
			if (!arg)
				continue;
			_exit = execute(arg, av, env, lineptr, nprocs);
			free(arg);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
	}
	return (_exit);
}
