#ifndef __SHELL__H
#define __SHELL__H

/* Library imports */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/* Constants */
#define BUFFER_SIZE 1024
#define MAX_TOKENS 64
#define DELIM_TOKENS " \n\t\r\v\b\f\a"
#define ENV_PATH "PATH"
#define ENV_VALUE_OFFSET 1
#define ENV_PATH_DELIM ":"
extern char **environ;

/**
* struct directoryPaths - A structure definition for a node in
* a linked list of directory paths.
* @directoryPath: Absolute path to a directory
* @next: A pointer to the next node in the linked list
*
*/
typedef struct directoryPaths
{
	char *directoryPath;
	struct directoryPaths *next;
} dir_paths;

void prompt(void);
char **tokenize(char *command, char *delim);
char *getProgramPath(char *progName);
dir_paths *buildEnvPathDirectoryList(char *envPathValue);
char *_getenv(char *envPath);
int isProgramPath(char *programPath);
char *getProgramPath(char *programName);
dir_paths *addNodeBegin(dir_paths **head, char *dirPath);
char *getPathFromEnv(char *envPathValue, char *programName);

/* De-allocate memory*/
void freeTokens(char **tokens);
void freeUserCommand(char **command, size_t *commandSize);
void freeDirectoryPathsList(dir_paths **head);

#endif /* #ifndef __SHELL__H */

