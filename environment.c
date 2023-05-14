#include "shell.h"

/**
* _getenv - Searches the environment array for
* an environment variable
* @envPath: environment variable
*
* Return: pointer to a copy of the environmnent
* variable's value
*/
char *_getenv(char *envPath)
{
	int i, envPathLen = strlen(envPath);

	i = 0;
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], envPath, strlen(envPath)) == 0)
			return (strdup(environ[i] + envPathLen + ENV_VALUE_OFFSET));
		++i;
	}
	return (NULL);
}

/**
* addNodeBegin - Adds a node to the beginning of a dir_paths
* linked list
* @head: Double pointer to the head node of a dir_paths list
* @dirPath: Absolute path to a directory
*
* Return: Pointer to the node added to the list
*/
dir_paths *addNodeBegin(dir_paths **head, char *dirPath)
{
	char *path = strdup(dirPath);
	dir_paths *node = malloc(sizeof(dir_paths));

	if (!node)
		return (NULL);
	node->directoryPath = path ? path : NULL;
	if (!(node->directoryPath))
		return (NULL);
	if (!(*head))
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		node->next = *head;
		*head = node;
	}

	return ((dir_paths *)node);
}

/**
* buildEnvPathDirectoryList - Creates a linked list of absolute
* paths to directories
* @envPathValue: The $PATH enviromnent variable value
* Description: Tokenizes the value of the PATH environment variable
* into paths to individual directories then adds them to the linked list.
*
* Return: Pointer to the head node of the dir_paths linked list
*/
dir_paths *buildEnvPathDirectoryList(char *envPathValue)
{
	dir_paths *head = NULL;
	int i;
	char *dirPath = strtok(envPathValue, ENV_PATH_DELIM);

	for (i = 0; dirPath; i++)
	{
		addNodeBegin(&head, dirPath);
		dirPath = strtok(NULL, ENV_PATH_DELIM);
	}
	return (head);
}

/**
* getPathFromEnv - Searches for a command program
* in the process' environment
* @envPathValue: Value of the $PATH environment variable
* @programName: The program name
*
* Return: Pointer to the updated program's path, NULL otherwise if
* program was not found or error
*/
char *getPathFromEnv(char *envPathValue, char *programName)
{
	dir_paths *head = NULL;
	char *programPath = NULL;
	dir_paths *dir_ptr = NULL;
	size_t programNameLen = strlen(programName);
	size_t dirPathLen = 0, fullPathLen = 0;

	head = buildEnvPathDirectoryList(envPathValue);
	dir_ptr = head;
	for (; dir_ptr;)
	{
		dirPathLen = strlen(dir_ptr->directoryPath);
		fullPathLen = programNameLen + dirPathLen + 2;
		programPath = malloc(sizeof(*programPath) * fullPathLen);
		if (!programPath)
			return (NULL);
		memcpy(programPath, dir_ptr->directoryPath, dirPathLen);
		memcpy(programPath + dirPathLen, "/", 1);
		memcpy(programPath + dirPathLen + 1, programName, programNameLen + 1);
		if (isProgramPath(programPath))
		{
			printf("New Path: %s\n", programPath);
			freeDirectoryPathsList(&head);
			return (programPath);
		}
		free(programPath);
		programPath = NULL;
		dir_ptr = dir_ptr->next;
	}
	freeDirectoryPathsList(&head);
	return (NULL);
}
