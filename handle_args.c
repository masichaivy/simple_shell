#include "shell.h"
/**
 * handle_args - handles the arguments cases.
 * @buffer: line entered by the user.
 * @buffer_copy: copied buffer.
 *
 * Return: Nothing.
 */
void handle_args(char *buffer, char *buffer_copy)
{
	const char *delimiter = " \t\n";
	char *token, **args;
	int tokens_number = 0, i = 0;

	token = strtok(buffer, delimiter);
	for (tokens_number = 0; token; tokens_number++)
		token = strtok(NULL, delimiter);
	tokens_number++;
	args = malloc(sizeof(char *) * tokens_number);
	if (args == NULL)
	{
		perror("args: malloc error");
		exit(0);
	}
	token = strtok(buffer_copy, delimiter);

	while (token)
	{
		args[i] = malloc(sizeof(char) * strlen(token));
		strcpy(args[i], token);
		token = strtok(NULL, delimiter);
		i++;
	}
	args[i] = NULL;
	exec_cmd(args);
	free(args);
}
