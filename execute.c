#include "shell.h"

/**
* execute_command - Executes commands from user input
* @args: The user input commands
* @env: The process's environment variables
*
* Return: void
*/
void execute_command(char **args, char **env)
{
	pid_t my_pid;
	int child_status = 0;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (my_pid == 0) /* Executed by child process */
	{
		execve(args[0], args, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else /* Executed by parent process */
	{
		wait(&child_status);
	}
}
