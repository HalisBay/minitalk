# minitalk

## Table of Contents
- [General Instructions](#general-instructions)
- [Project Instructions](#project-instructions)
- [Mandatory Part](#mandatory-part)
- [Usage](#usage)

## General Instructions
- Your projects must be written in C.
- Except for undefined behaviors, your functions should not terminate unexpectedly (segmentation fault, bus error, double free, etc.).
- All heap-allocated memory addresses must be properly freed when necessary. No exceptions will be tolerated.
- If the task requires submitting a Makefile, you must create a Makefile that compiles your source files with the flags `-Wall`, `-Wextra`, and `-Werror`. Use `cc` for compiling, and your Makefile must not relink.
- Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

## Project Instructions
- Name your executable files as `client` and `server`.
- You should add the necessary additions to the Makefile to compile the source files. Additionally, the Makefile should not relink.
- You can use your `libft` project.
- You should handle errors thoroughly. Your program should not terminate unexpectedly (segmentation fault, bus error, double free, etc.).
- Your program must not have memory leaks.
- You may have one global variable per program (one for the client and one for the server), but it should only be used where necessary.
- To complete the mandatory part, you are allowed to use the following functions:
  - `write`
  - `ft_printf` or any equivalent function you have coded
  - `signal`
  - `sigemptyset`
  - `sigaddset`
  - `sigaction`
  - `kill`
  - `getpid`
  - `malloc`
  - `free`
  - `pause`
  - `sleep`
  - `usleep`
  - `exit`

## Mandatory Part
You need to create a communication program in the form of a client and a server.
- First, the server should be started. Upon starting, it should print its PID.
- The client takes two parameters:
  - The server PID.
  - The string to be sent.
- The client should send the string provided as a parameter to the server. The server should print the string once received.
- The server should print the string very quickly. If you think it takes too long, it is probably too long. Taking 1 second to display 100 characters is too much!
- The server should be able to receive strings from several clients in a row without needing to be restarted.
- Communication between the client and the server must be done using only UNIX signals.
- You are only allowed to use the following two signals: `SIGUSR1` and `SIGUSR2`.

## Usage
To run the programs, use the following commands:

### Server
```bash
./server
```
### Client
```bash
./client <server_pid> <string>
