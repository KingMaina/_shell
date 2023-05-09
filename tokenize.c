#include "shell.h"

/**
* tokenize - Breaks down a command string int an array of tokens
* @command: The command string
* @delim: The delimeter to use when tokenizing
*
* Return: A pointer to an array of tokens. NULL otherwise on error
*/
char **tokenize(char *command, char *delim)
{
	char **tokens = NULL;
	char *token = strtok(command, delim);
	size_t tokenCount = 0;

	while (token)
	{
		tokens = realloc(tokens, sizeof(*tokens) * ++tokenCount);
		if (!tokens)
			exit(EXIT_FAILURE);
		tokens[tokenCount - 1] = strdup(token);
		token = strtok(NULL, delim);
	}
	tokens = realloc(tokens, sizeof(*tokens) * (tokenCount + 1));
	tokens[tokenCount] = NULL;

	return (tokens);
}
