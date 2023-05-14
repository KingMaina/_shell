#include "shell.h"

/**
* main - Application entry
* @argc: The number of arguments passed to the application
* @argv: A NULL terminated array list of the program's arguments
* @env: A NULL terminated list of the process's environment variables
*
* Return: 0 on success, non-zero on error
*/
int main(int argc, char **argv, char **env)
{
	char *userCommand = NULL;
	size_t userCommandSize = 0;
	ssize_t bytesRead = 0;
	char **tokens = NULL;
	char *progName = NULL;

	while (argc && 1)
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
		{
			freeUserCommand(&userCommand, &userCommandSize);
			freeTokens(tokens);
			continue;
		}
		progName = getProgramPath(tokens[0]);
		if (!progName)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
			freeUserCommand(&userCommand, &userCommandSize);
			freeTokens(tokens);
			continue;
		}
		free(tokens[0]);
		tokens[0] = progName;
		execute_command(tokens, env);
		freeUserCommand(&userCommand, &userCommandSize);
		freeTokens(tokens);
	}

	return (EXIT_SUCCESS);
}

