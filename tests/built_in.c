#include "holberton.h"

int lsh_cd(char **args);
int lsh_help(char *);
int lsh_exit(char *);

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
/**
 *lsh_num_builtins - returns the size builtin commands
 *Return: 1 on success
 */

int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * lsh_cd - change directory
 *@args: arguments
 *Return: 1 on success
 */
int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	} else
	{
		if (chdir(args[1]) != 0)

			perror("lsh");

	}
	return (1);
}
/**
 *lsh_help - prints help
 * @args: argument parameter
 *Return: 1 on success
 */

int lsh_help(char *args)
{
	int i;

	printf(" EGG SHELL\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}
/**
 *lsh_exit - exits the shell
 *@args: arguments
 *Return: 0 on success
 */


int lsh_exit(char *args)
{
	return (0);
}


