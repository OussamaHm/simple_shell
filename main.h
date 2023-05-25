#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#csisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - holds the main data.
 * @av: Array of tokens to pass for execve
 * @cmd: The user input, the command line
 * @nomShell: The name of the shell program
 * @last_exit_stats: last exit stats of last command executed
 * @flag_setenv: 1 if user did exec setenv (use it to free memory)
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *nomShell;
	int last_exit_stats;
	int flag_setenv;
} data;

/**
 * struct builtN - holds the main data.
 * @cmd: built in cmd
 * @f: function of builtN cmd
 */
typedef struct builtN
{
	const char *cmd;
	void (*f)(data *d);
} builtN;



/* helpers.c */
void _printf(const char *str);
void free_array(char **array);
void split(data *d, const char *delimouta);
void init_data(data *d, const char *nomShell);
void read_cmd(data *d);

/* exec.c */
void start_process(data *d);
void handler_sigint(int sig);
void _exec(data *d);

/* string_utils.c */
unsigned int _strlen(char *str);
int _strcmp(const char *sotoring1, const char *sotoring2);
int _strncmp(const char *sotoring1, const char *sotoring2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);


/* helpers2.c */
void _perror(const char *stringuu1, const char *stringuu2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int nouveau_siz);


/* path.c */
char *_getenv(char *name);
int _which(data *d);
int _setenv(data *d, char *name, char *value);

/* string_utils2.c */
char *_strdup(const char *str);
int _isnumber(const char *stats);
int _isdigit(int c);

/* builtN.c */
int exec_builtN(data *d);
void builtN_exit(data *d);
void builtN_env(data *d);
void builtN_setenv(data *d);
void builtN_unsetenv(data *d);
void builtN_cd(data *d);


/* _getline.c */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **Lptr, size_t *n, FILE *stmr);


#endif


