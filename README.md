# Minishell

*This project has been created as part of the 42 curriculum.*

## Description

Minishell is a project from the 42 curriculum whose goal is to recreate a simplified version of a Unix shell. It behaves similarly to Bash, allowing users to type commands, execute programs, and interact with the operating system through a command-line interface.

The main objective of this project is to understand how a shell works internally. This includes parsing user input, handling processes, managing file descriptors, and executing commands using system calls.

The shell supports execution of commands through the `PATH` environment variable as well as absolute and relative paths. It also handles input/output redirections, pipes, environment variables, and basic signal handling.

Through this project, we gain a deeper understanding of process creation using `fork`, program execution using `execve`, and inter-process communication using pipes, as well as overall system-level programming concepts in C.