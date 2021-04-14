# Simple Shell program

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

This is a simple shell implementation to execute shell-like commands. You have to compile all the files for thest the program.   

- Writing in C
- For Ubuntu 14.04 LTS      
- With memory Magic ✨✨✨
✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨

## Environment
This shell was built and tested in Ubuntu 14.04 LTS in a virtual machine and compiled with GCC 4.8.4

## Respository Contents
Files for compile the simple shell.

| **File** | **Description** |
|----------|-----------------|
| holberton.h | Header file that contains all the functions and standard C library header file |
| main.c | Contains the entry entry point: **main**, **interactive_mode**, **no_interactive_mode** and **sigintHandle** functions |
| Process_execution.c | Contains function that validate and execute process: **fork_execution**, **function_execution** |
| Auxiliar_function.c | Contains all helper functions: **_strcmp**,**_strlen**, **_strncmp**, **_strcpy** |
| Linked_list_handler.c | Contains all functions that handle linked list: **add_node_end**, **conc_check_list**, **free_list** |
| Command_handler.c | Contains function that handle the prompt input: **buff_separator**, **count_commands** |
| Builtins.c | Contains functions that handle builtins commands: **builtin_compare**, **builtin_execution**, **check_buffer** |
| Path_handler.c | Contains functions that handle the PATH: **check_path**, **get_path** |

## Installation

On Ubuntu 14.04 LTS terminal, clone the repo with the next command:

```sh
git clone https://github.com/Cmart94/simple_shell.git
```
## Compile
Compile all .c and header files with the nex command:
```sh
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
The output is a executable file hsh. Your terminal should look like:
``` sh
vagrant@vagrant-ubuntu-trusty-64:$ .gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
vagrant@vagrant-ubuntu-trusty-64:$ ./hsh
$ ls -la
total 176
-rw-rw-r-- 1 vagrant vagrant   186 Apr 14 03:44 AUTHORS             
-rw-rw-r-- 1 vagrant vagrant  6566 Apr 14 03:44 README.md           
-rw-rw-r-- 1 vagrant vagrant   645 Apr 14 02:11 _fork_execution.c   
-rw-rw-r-- 1 vagrant vagrant   353 Apr 13 02:21 Process_execution.c          
-rw-rw-r-- 1 vagrant vagrant   229 Apr 14 02:11 Auxiliar_function.c          
-rw-rw-r-- 1 vagrant vagrant   415 Apr 13 16:07 Linked_list_handler.c         
-rw-rw-r-- 1 vagrant vagrant   398 Apr 13 16:07 Command_handler.c         
-rw-rw-r-- 1 vagrant vagrant   644 Apr 13 02:21 Builtins.c      
-rw-rw-r-- 1 vagrant vagrant   875 Apr 13 17:09 Path_handler.c   
-rw-rw-r-- 1 vagrant vagrant  1523 Apr 14 02:11 holberton.h         
-rwxrwxr-x 1 vagrant vagrant 19226 Apr 14 17:54 hsh                 
-rw-rw-r-- 1 vagrant vagrant  2050 Apr 14 02:41 main.c              
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
``` 
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh

## Examples
For test the interactive mode just execute the hsh file and test commands.
``` sh
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
#cisfun$ pwd
/home/vagrant/simple_shell
#cisfun$ ps
  PID TTY          TIME CMD
 1853 pts/0    00:00:00 bash
 3403 pts/0    00:00:00 hsh
 3405 pts/0    00:00:00 ps
#cisfun$
```

For test the no interactive mode and execute severla commands, run the program hsh like this:
``` sh
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo "pwd
> ps
> ls -l" | ./hsh
/home/vagrant/simple_shell
  PID TTY          TIME CMD
 1853 pts/0    00:00:00 bash
 3403 pts/0    00:00:00 hsh
 3405 pts/0    00:00:00 ps
total 116                                                           
-rw-rw-r-- 1 vagrant vagrant   186 Apr 14 03:44 AUTHORS             
-rw-rw-r-- 1 vagrant vagrant  6566 Apr 14 03:44 README.md           
-rw-rw-r-- 1 vagrant vagrant   645 Apr 14 02:11 _fork_execution.c   
-rw-rw-r-- 1 vagrant vagrant   353 Apr 13 02:21 Process_execution.c          
-rw-rw-r-- 1 vagrant vagrant   229 Apr 14 02:11 Auxiliar_function.c          
-rw-rw-r-- 1 vagrant vagrant   415 Apr 13 16:07 Linked_list_handler.c         
-rw-rw-r-- 1 vagrant vagrant   398 Apr 13 16:07 Command_handler.c         
-rw-rw-r-- 1 vagrant vagrant   644 Apr 13 02:21 Builtins.c      
-rw-rw-r-- 1 vagrant vagrant   875 Apr 13 17:09 Path_handler.c   
-rw-rw-r-- 1 vagrant vagrant  1523 Apr 14 02:11 holberton.h         
-rwxrwxr-x 1 vagrant vagrant 19226 Apr 14 17:54 hsh                 
-rw-rw-r-- 1 vagrant vagrant  2050 Apr 14 02:41 main.c              
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$                    
```
To exit the shell press **ctrl + D**

## Authors
* [**Mateo Londoño Correa**](https://github.com/Matteo-lu)
* [**Cristian Martinez Pino**](https://github.com/NickolasTeixiera)

## Legal
Use and transfer of Simple Shell may be subject to certain restrictions by Colombia and other governments.
It's your responsibility to ensure that you use and/or transfer does not violate applicable laws.

## Licensing
Simple Shell is licensed under the MIT License.
**Free Software, Hell Yeah!**