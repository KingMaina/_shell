#include "shell.h"

/**
* isProgramPath - Check the existence and execute permissions
* for a file
* @programPath: Absolute path to the program
*
* Return: 1 if the file is found and can be executed,
* 0 if file not found or execute permissions are denied
*/
int isProgramPath(char *programPath)
{
	if (programPath && access(programPath, X_OK) == 0)
		return (1);
	return (0);
}

/**
* getProgramPath - Searches for the program path
* @programName: Then name of the program
*
* Return: Pointer to the program path, NULL otherwise if
* program path not found
*/
char *getProgramPath(char *programName)
{
	char *envPathValue = NULL, *programPath = NULL;

	if (!programName)
		return (NULL);
	if (isProgramPath(programName))
		return (strdup(programName));
	envPathValue = _getenv(ENV_PATH);
	programPath = getPathFromEnv(envPathValue, programName);
	free(envPathValue);
	return (programPath);
}
