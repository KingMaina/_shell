# UNIX SHELL PROGRAM

This will be a simple project aimed at building a simple UNIX shell program using the C programming language.

## WHAT'S NEW🚀

The shell executes simple commands and works in a Read-Execute-Print-Loop (REPL) manner.
The shell however cannot execute complex commands such as:
1. Built-in commands like `cd`, `alias`.
2. Logical properties such as `||` and `&&`.
3. I/O redirection i.e. `>`, `<` or `>>`

## Description📜

This is a shell program that reads user commands, parses them and executes the commands like the `bash`, `sh` etc. shells.

## Project Setup⛏
### 0.Tools and Technologies

![VIM](https://img.shields.io/badge/VIM-%2311AB00.svg?&style=for-the-badge&logo=vim&logoColor=white)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

Ensure you have the following installed in your machine or run the docker container(COMING SOON).
If you are on linux or similar supported UNIX OS:
 - `gcc` GNU Compiler Collection
 - `valgrind` Inpect memory usage of application.
 - `gdb` - GNU Debugger to hunt down bugs in logic

### 1.Compile project files

Once you have cloned the repository, compile the program using the code below:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c prompt.c -o ./my_shell
```

To compile the code for debugging with gdb, add the `-g` flag to compile into a form that can be used by the debugger.
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c prompt.c -g -o ./d_my_shell
```
and run the debugger:
```sh
gdb ./d_myshell
```
For more on learning how to use the debugger, visit the official docs at [gdb docs](https://sourceware.org/gdb/current/onlinedocs/gdb.html/)
## 2.Run the shell

To run the shell program in interactive mode:
```sh
./my_shell
```
Enter commands on the standard output, keyboard by default, using the format:
```sh
$ <command_name> [...arguments]
```
### 3.Example📝
List the directory's contents excluding hidden files and directories (defaults to the current directory as no target directory has been specified). 
```sh
$ ls -la # or /bin/ls -l
d_my_shell     execute.c  main.c    my_shell  README.md  shell.h
environment.c  LICENSE    memory.c  prompt.c  search.c   tokenize.c
```
but not complex commands such as:
```sh
$ echo "Hello World" > hello.txt && cat hello.txt 
```
## 4.Give Feedback🔄

![Ask Me Anything](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)

I would love to hear what you think about this project and suggest new features to add.

