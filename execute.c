#include "holberton.h"
/**
 * _launch- starts the process for the shell program
 * @args: pointer to arguments
 * Return: void
 */
int _launch(char **args)
{
	pid_t pid, ppid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/*child process*/
		if (execvp(args[0], args) == -1)
		{
			perror("sh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Error forking*/
		perror("sh");
	}
	else
	{
		/**Parent process*/
		do {
			ppid = waitpid(pid, &status, WUNTRACED);
		} while (WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
/**
 * _execute - launch a builtin or a process
 * @args: arguments to be passed i
 * Return: launched process
 */
int _execute(char **args)
{
	int i;
	/*
	 *   List of builtin commands, followed by their corresponding functions.
	 *    */

	int lsh_cd(char **args);
	int lsh_help(char **args);
	int lsh_exit(char **args);
	
	char *builtin_str[] = {
		"cd",
		"help",
		"exit"
	};

	int (*builtin_func[]) (char **) = {
		&lsh_cd,
		&lsh_help,
		&lsh_exit
	};

	int lsh_num_builtins() {
		  return sizeof(builtin_str) / sizeof(char *);
	}
	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (*builtin_func[i])(args);
		}
	}
	return _launch(args);
}
