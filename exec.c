#include "main.h"

/**
 * start_process - start a new process
 * @d: data struct input
 * Return: void
 */

void start_process(data *d)
{
	pid_t chipid = fork();
	int stt = 0;
	if (chipid == -1)
		goto free;
	if (chipid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&stt) == -1)
		goto free;
	if (WIFEXITED(stt))
		d->last_exit_stt = WEXITSTATUS(stt);
	return;
free:
	perror(d->shell_nm);
	free_arr(d->av);
	free(d->cmd);
	exit(EXIT_FAILURE);
}

/**
 * handler_sigint - Signal handler function
 * @signal: int input
 * Return: void
 */

void handler_sigint(int signal)
{
	/*const char prpt[] = PROMPT;*/
	(void)signal;
	exit(EXIT_FAILURE);
	/*_printf(prpt);*/
}

/**
 * _exec - exectute cmd
 * @d: data struct input
 * Return: void
 */

void _exec(data *d)
{
	const char prpt[] = PROMPT;

	signal(SIGINT, handler_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prpt);

		read_cmd(d);
		if (_strlen(d->cmd) != 0)
		{
			split(d, " ");
			if (!exec_builtin(d))
			{
				_which(d);
				if (access(d->av[0], F_OK) == -1)
				{
					perror(d->shell_nm);
				}
				else
				{
					start_process(d);
				}
			}
			free_arr(d->av);
		}
		free(d->cmd);
	}
}

