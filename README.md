# minishell
Minishell is a simple shell program written in C. It provides a command-line interface that allows users to interact with their computer through a series of commands. This project aims to replicate the functionality of a basic shell, similar to Bash, and provides a set of features and functionalities that allow users to execute commands, handle processes, and perform various operations on files and directories.


## Features

- **Prompt**: Minishell displays a prompt when waiting for a new command, indicating that it is ready to accept user input.
- **Command Execution**: The shell searches for and launches the appropriate executable based on the PATH variable, or using a relative or absolute path.
- **History**: Minishell maintains a working history of previously executed commands, allowing users to navigate and recall previous commands.
- **Quotes Handling**: The shell interprets and handles single quotes ('), preventing the interpretation of metacharacters within the quoted sequence. Double quotes (") prevent interpretation of metacharacters, except for the dollar sign ($).
- **Redirections**: Minishell supports input (<) and output (>) redirection, allowing users to redirect the input or output of a command to/from a file. Append mode (>>) for output redirection is also supported. Here documents (<<) can be used to read input until a specified delimiter is encountered.
- **Pipes**: The shell supports pipes (|) to connect the output of one command as the input of another command in a pipeline.
- **Environment Variables**: Minishell handles environment variables ($ followed by a sequence of characters) and expands them to their corresponding values.
- **Built-in Commands**: The shell implements several built-in commands, including echo, cd, pwd, export, unset, env, and exit.
- **Signal Handling**: Minishell handles signals such as ctrl-C, ctrl-D, and ctrl-\ in an interactive mode, providing behavior similar to Bash.

## Installation

To compile and run Minishell, follow these steps:

1. Clone the repository: `git clone <repository-url>`
2. Navigate to the project directory: `cd minishell`
3. Compile the source code: `make`
4. Run Minishell: `./minishell`

## 🔗 Ressources
[ultimate docs](https://docs.google.com/document/d/16_Yke-F4R1w_JIwhj9aovZIUchjfxO11AOAriKwX_KQ/edit#heading=h.m1z9chnw1mt0)
