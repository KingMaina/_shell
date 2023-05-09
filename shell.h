#ifndef __SHELL__H
#define __SHELL__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define MAX_TOKENS 64
#define DELIM_TOKENS " \n\t\r\v\b\f\a"

void prompt(void);
void freeUserCommand(char **command, size_t *commandSize);
char **tokenize(char *command, char *delim);
void freeTokens(char **tokens);

#endif /* #ifndef __SHELL__H */
