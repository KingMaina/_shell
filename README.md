# Project Details

This will be a simple project aimed at building a simple UNIX shell program using the C programming language.
Documentation wil be updated soon upon completion of feature (feature-tokenization)[#].
The shell in its current state cannot execute commands like ```bash``` because the feature has not been implemented until after tokenization and environment path searching is done. You can watch/star the project to keep up with updates to the project.
Explanations on the gcc flags and any other unexplained code will be updated as more featres are added.
## Description

This is a shell program that reads user commands, parses them and executes the commands like the `bash`, `hsh` shells etc.

## Project Setup

Ensure you have the following installed in your machine or run the docker container(COMING SOON).
If you are on linux or similar supported UNIX OS:
 - `gcc` GNU C Compiler.
 - `valgrind` Inpect memory usage of application.
 - 'gdb' - GNU Debugger.

### Compile project files

Once you have cloned the repository, compile the program using the code below:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c prompt.c -o ./my_shell
```

## Run the shell

To run the shell program in interactive mode:
```bash
./my_shell
```
Enter commands on the standard output, keyboard by default, using the format:
```bash
<command> ...[arguments]
```
### Example
```bash
echo "Hello World"
```
