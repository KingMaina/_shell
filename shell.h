#ifndef __SHELL__H
#define __SHELL__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void prompt(void);
void freeUserCommand(char **command, size_t *commandSize);

#endif /* #ifndef __SHELL__H */
