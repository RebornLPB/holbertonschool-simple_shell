# C - Simple Shell

## Description
This project is a custom UNIX command-line interpreter (shell) implemented in C as part of the **Holberton School** curriculum. Developed in a pair programming environment by **RebornLPB** and **Theo Vincenzi**, this program replicates the basic core functionalities of `sh` (`/bin/sh`).

It reads command lines from standard input, parses execution arguments, searches for executable files within the `PATH` environment variable, handles process creation via system calls (`fork`, `execve`, `wait`), manages EOF (`Ctrl+D`), and executes built-in commands like `exit` and `env`.

All source files adhere strictly to the **Betty coding style**.

## 📝 Learning Objectives
* Understand how a command-line interpreter works under the hood.
* Master process creation and management using system calls: `fork`, `execve`, `wait`, `waitpid`, and `exit`.
* Handle the environment array (`environ`) and manipulate the `PATH` variable to find binary executables.
* Understand the difference between system calls and standard library functions.
* Master memory allocation and cleanup to prevent memory leaks in long-running processes.
* Handle EOF (`Ctrl+D`) gracefully and intercept signals like `SIGINT` (`Ctrl+C`).

## 🛠️ Requirements & Engineering Constraints
* **OS:** Ubuntu 20.04 LTS
* **Compiler:** `gcc` (Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`)
* **Coding Style:** 100% compliant with the Betty Style Guide (`betty-style.pl` and `betty-doc.pl`).
* **Memory Safety:** Zero memory leaks verified using Valgrind.
* **Allowed Functions & System Calls:** `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat` (`__xstat`), `lstat` (`__lxstat`), `fstat` (`__fxstat`), `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`.

## 📁 Repository Structure

```text
.
├── shell.h           # Main header file containing structures, macros, and prototypes
├── main.c            # Entry point for interactive and non-interactive shell modes
├── parser.c          # Tokenization logic using strtok to parse command arguments
├── executor.c        # Process execution engine (fork, execve, wait status handling)
├── path.c            # Path lookup resolution engine traversing PATH directories
├── builtins.c        # Custom built-in command handlers (exit, env)
├── helpers.c         # String utilities and memory allocation helper routines
├── man_1_simple_shell# Custom manual page for the simple shell
└── README.md         # Project documentation
```

---

## 💻 Interactive vs Non-Interactive Mode

The shell supports two modes of execution:

### Interactive Mode
Run the executable directly from your terminal. It displays a prompt `($ )`, reads your inputs, executes commands, and waits for further commands until exited:

```bash
$ ./hsh
($ ) /bin/ls
main.c  parser.c  executor.c  shell.h  hsh
($ ) pwd
/home/user/holbertonschool-simple_shell
($ ) exit
$
```

### Non-Interactive Mode
Pipe command strings or redirect input files directly into the shell:

```bash
$ echo "/bin/ls" | ./hsh
main.c  parser.c  executor.c  shell.h  hsh
$
$ echo "pwd" | ./hsh
/home/user/holbertonschool-simple_shell
$
```

---

## 🚀 Compilation & Installation

To compile the shell, run the following command in your terminal:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Testing Memory Safety with Valgrind
To verify that all dynamically allocated strings, buffers, and env vectors are freed cleanly upon termination:

```bash
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./hsh
```

Expected output signature:
All heap blocks were freed -- no leaks are possible

---

## 📖 Manual Page Access

To view the custom man page for the shell:

```bash
man ./man_1_simple_shell
```

---

## 👥 Authors & Acknowledgments

This project was developed as a pair programming effort by:

* **Student 1:** [RebornLPB](https://github.com/RebornLPB)
* **Student 2:** [Theo Vincenzi](https://github.com/theovincenzi) *(or update with his exact GitHub link)*
* **School:** [Holberton School](https://www.holbertonschool.com/)