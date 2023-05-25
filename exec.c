#include "main.h"

/**
 * start_process - start a new process
 * Return: void
 * @d: data struct input
 */

void start_process(data *d)
{
	pid_t le_fils_de_pid = fork();
	int stats = 0;

	if (le_fils_de_pid == -1)
		goto free;
	if (le_fils_de_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&stats) == -1)
		goto free;
	if (WIFEXITED(stats))
		d->last_exit_stats = WEXITSTATUS(stats);
	return;
free:
	perror(d->nomShell);
	free_array(d->av);
	free(d->cmd);
	exit(EXIT_FAILURE);
}



/**
 * _exec - exectute cmd
 * Return: void
 * @d: data struct input
 */

void _exec(data *d)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, handler_sigint);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		read_cmd(d);
		if (_strlen(d->cmd) != 0)
		{
			split(d, " ");
			if (!exec_builtN(d))
			{
				_which(d);
				if (access(d->av[0], F_OK) == -1)
				{
					perror(d->nomShell);
				}
				else
				{
					start_process(d);
				}
			}
			free_array(d->av);
		}
		free(d->cmd);
	}
}

/**
 * handler_sigint - Signal handler function
 * Return: void
 * @signal: int input
 */

void handler_sigint(int signal)
{
	/*const char prompt[] = PROMPT;*/
	(void)signal;
	exit(EXIT_FAILURE);
	/*_printf(prompt);*/
}


