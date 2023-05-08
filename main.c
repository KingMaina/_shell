#include "shell.h"

/**
* main - Application entry
*
* Return: 0 on success, non-zero on error
*/
int main(void)
{
	char *userCommand = NULL;
	size_t userCommandSize = 0;
	ssize_t bytesRead = 0;

	while (1)
	{
		prompt();
		freeUserCommand(&userCommand, &userCommandSize);
		bytesRead = getline(&userCommand, &userCommandSize, stdin);
		if (bytesRead == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			freeUserCommand(&userCommand, &userCommandSize);
			break;
		}
	}

	return (EXIT_SUCCESS);
}
