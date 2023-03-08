#include "holberton.h"
/**
 * sh_read_line - read line from stndard input
 * Return: pointer to line
 */
char *sh_read_line(void)
{

	char *line = NULL;
	ssize_t bufsize = 0;
	ssize_t res;
	/* getline to allocate a buffe */
	res = getline(&line, &bufsize, stdin);
	if (res == -1)
	{
		if (feof(stdin))
		{
			/*Receive an EOF*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);

	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;
	if (!buffer)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "sh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/**
 * sh_split_line - Split a line into tokens (very naively).
 * line: The line.
 * Return: Null-terminated array of tokens.
 * */
char **sh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens) {
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += LSH_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				free(tokens_backup);
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
/**
 * sh_loop - function that interprets commands
 * _read_line: parsing line, get input frmo user
 * _split_line: parse the line to list of arguments
 * Return: Void
 */
void sh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = sh_read_line();
		args = sh_split_line(line);
		free(line);
		free(args);
	} while (status);
}
/**
 * Main - Main entry point.
 * argc:  Argument count.
 *  args:  Argument vector.
 * Return:  status code
 */
int main(int argc, char **args)
{
	sh_loop();

	return (EXIT_SUCCESS);
}
