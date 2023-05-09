#include "shell.h"

/**
* main - Application entry
*
* Return: 0 on success, non-zero on error
*/
int main(void)
{
	char *userCommand = NULL;
	size_t userCommandSize = 0, numTokens = 0, i;
	ssize_t bytesRead = 0;
	char **tokens = NULL;

	while (1)
	{
		prompt();
		bytesRead = getline(&userCommand, &userCommandSize, stdin);
		if (bytesRead == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			freeUserCommand(&userCommand, &userCommandSize);
			break;
		}
		if (userCommand[0] == '\n')
			continue;
		tokens = tokenize(userCommand, DELIM_TOKENS);
		if (!tokens)
			continue;
		for (i = 0; tokens[i]; i++)
			numTokens++;
		freeUserCommand(&userCommand, &userCommandSize);
		freeTokens(tokens);
	}

	return (EXIT_SUCCESS);
}
