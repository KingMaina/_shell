# Project Details

This will be a simple project aimed at building a simple UNIX shell program using the C programming language.
The shell in its current state cannot execute commands like ```bash``` because the feature has not been implemented until after tokenization and environment path searching is done. You can watch/star the project to keep up with updates to the project.
Explanations on the gcc flags and any other unexplained code will be updated as more featres are added.

## WHAT'S NEW
The shell program can accept absolute command paths as well as short forms e.g.
```bash
$ ls -la // evaluates to /bin/ls -la
$ /bin/ls -la // uses the absolute path but still works regardless.
```

## Description

This is a shell program that reads user commands, parses them and executes the commands like the `bash`, `sh` etc. shells.

### Example
```bash
$ ls -la /var/tmp
$ man echo
```

## Project Setup

### Tools and Technologies

![Built with VIM](https://img.shields.io/badge/VIM-%2311AB00.svg?&style=for-the-badge&logo=vim&logoColor=white)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

Ensure you have the following installed in your machine or run the docker container(COMING SOON).
If you are on linux or similar supported UNIX OS:
 - `gcc` GNU Compiler Collection
 - `valgrind` Inpect memory usage of application.
 - `gdb` - GNU Debugger to hunt down bugs in logic

### Compile project files

Once you have cloned the repository, compile the program using the code below:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c prompt.c -o ./my_shell
```

To compile the code for debugging with gdb, add the `-g` flag to compile into a form that can be used by the debugger.
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c prompt.c -g -o ./d_my_shell
```

## Run the shell

To run the shell program in interactive mode:
```bash
./my_shell
```
Enter commands on the standard output, keyboard by default, using the format:
```bash
$ <command_name> [...arguments]
```

## Feedback

![Ask Me Anything](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)

I would love to hear what you think about this project and suggest new features to add.
