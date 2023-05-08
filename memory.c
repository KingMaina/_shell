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
