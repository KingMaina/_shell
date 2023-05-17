# **🚀UNIX SHELL PROGRAM🚀**

This will be a simple project aimed at building a simple UNIX shell program using the C programming language.


## WHAT'S NEW🚀

The shell executes simple commands and works in a Read-Execute-Print-Loop (REPL) manner.
1. Simple shell commands such as `echo "Hello"`, `ls -la /var/tmp`


## Work in progress
The following features will be introduced in future versions:
1. Built-in commands like `cd`, `alias`.
2. Logical properties such as `||` and `&&`.
3. I/O redirection i.e. `>`, `<` or `>>`.
4. Navigation using arrow keys (The cursor currently does not move when you press up, down, left, right etc).
5. Shell history.


## Description📜

This is a shell program that reads user commands, parses them and executes the commands like the `bash`, `sh` etc. shells.
All commands described below assume you are familiar with linux, interacting with the command line and is using a unix shell like `sh`, `bash`, `zsh` etc. in a unix-like  variant system such as Linux, Ubuntu etc.
Be sure to check out how to [Setup](#project-setup) the project environment then check out the [Example](#3-example) section to see how to interact with the shell.

## Project Setup⛏

![VIM](https://img.shields.io/badge/VIM-%2311AB00.svg?&style=for-the-badge&logo=vim&logoColor=white)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

Ensure you have the following installed in your machine or run the docker container(COMING SOON).
If you are on linux or similar supported UNIX OS:
 - `gcc` GNU Compiler Collection to compile the source files if running locally
 **optional**
 - `valgrind` Inspect memory usage of application.
 - `gdb` - GNU Debugger to hunt down bugs in logic etc.
 - `docker` - For creating and running the shell in a containerised environment.


## 1. Compile project file

Once you have cloned the repository, change directory into the repo directory and compile the program using the code below:
```sh
cd _shell/ # Change into the directory context
```
```sh
gcc *.c -o my_shell
```

To compile the code for debugging with gdb, add the `-g` flag to compile into a form that can be used by the debugger.
```sh
gcc *.c -g -o d_my_shell
```
and run the debugger:
```sh
gdb ./d_myshell
```
You can add optional flags to use various gcc features such as compliance to specific C standards or issue warnings and errors in the compilation process.
```sh
gcc -Wall -Werror -Wextra -pedantic -std-gnu89 *.c -o my_shell
```
For more on learning how to use the debugger, visit the official docs at [gdb docs](https://sourceware.org/gdb/current/onlinedocs/gdb.html/)


## 2. Run the shell
### i. Locally

To run the shell program in interactive mode:
```sh
./my_shell
```
Enter commands on the standard output, keyboard by default, using the format:
```sh
$ <command_name> [...arguments]
```
See [examples](#3-example) section below.

### ii. Docker

1. Build the docker image. The `Dockerfile.dev` file in the current directory will be used because we specify `.` as the path.
```sh
docker build -t shell_image .
```
2. Run the container using the image created above.
```sh
docker run -it --rm --name my_shell shell_image
```
	- `-it` instructs docker to provide you with an interactive shell inside the container so
	that you can execute commands.
	- `--rm` tells docker to delete the contaier once it stops running, otherwise you have to
	delete the container manually using `docker rm <container name or hash>`
	- `--name` gives the container a name; In this case, we call it `my_shell`.
3. Write simple commands in the prompt once the container is running

## 3. Example📝
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
To exit the shell, issue a `Ctrl-D`/`EOF` signal and terminate the shell program. This can be done while running the shell locally or using the docker container.
If used while you have launched valgrind, it will terminate the shell program running in valgrind first and give a summary of memory usage, then prompt the user again for a command. Press Ctrl-D again to terminate the shell.
> This is temporary for now as built-in commands such as `exit` to **exit** the shell have not been implemented yet.

## 4. Memory check with Valgrind

If you want to check the heap memory usage of the application, run using the compiled shell program `my_shell` or the debugging executable file `d_my_shell`.
You can use valgrind from your local environment if you have installed it or you can use the one installed in the container. You can access it through the interactive shell as follows:
```sh
$ valgrind ./my_shell ## or valgrind ./d_my_shell
```
Once it launches, issue commands from the terminal prompt just like you would in any other shell program. See [examples](#3-example) above.

## 5.Give Feedback🔄

![Ask Me Anything](https://img.shields.io/badge/Ask%20me-anything-1abc9c.svg)

I would love to hear what you think about this project and suggest new features to add.

