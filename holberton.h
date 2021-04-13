#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * struct list_s - Short description
 * @str: pointer to separate PATH
 * @next: Pointer to next node
 *
 * Description: this structure is of type linked list, to hold the separe PATH
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str);
char **buff_separator(char *str, char *identificator);
char *conc_check_list(list_t **head, char *aux1);
void free_list(list_t *head);
int _strcmp(char *s1, char *s2);
char *get_path(void);
int env_function(void);
int isatty(int fd);
int count_commands(char *str_read);
void function_execution(char array_master[], char *path);
int check_path(char *array);
void fork_execution(char **array_words);
char *builtin_compare(char *str);
void builtin_execution(char *builtmatch, char *argv[]);
void sigintHandler(int sig_num);
int check_buffer(char *buffer);
char *get_path(void);
int _strncmp(char *s1, char *s2, size_t size);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
char *conc_check_list(list_t **head, char *aux1);
char *_strcpy(char *src);
void interactive_mode(char *path);
void no_interactive_mode(char *path);

extern char **environ;

#endif
