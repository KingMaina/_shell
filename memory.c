#include "shell.h"

/**
* freeUserCommand - De-allcoates memory allocated for the command
* input buffer.
* @command: Pointer to the command input buffer address
* @commandSize: Size of the command input buffer
*
* Return: void
*/
void freeUserCommand(char **command, size_t *commandSize)
{
	if (!command || !(*command) || *commandSize <= 0)
		return;
	free(*command);
	*command = NULL;
	*commandSize = 0;
}

/**
* freeTokens - De-allocates memory for a NULL-terminated
* tokens array
* @tokens: pointer to the token array
*
* Return: void
*/
void freeTokens(char **tokens)
{
	size_t i;

	if (!tokens || !(*tokens))
		return;
	for (i = 0; tokens && tokens[i]; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
	tokens = NULL;
}

