#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZ 1024
#define DELIMETER " \t\r\n\a"
#define PRINTF(str) (write(STDOUT_FILENO, str, my_strlen(str)))
extern char **environ;

/****************ERROE MESSAGE*******************/
void dis_err(char *line, int run, char **argv);
void my_perror(char **argv, int str, char **line);
void my_error(char **argv, int str);

/****************BUILTIN************************/
int builtin_val(char **line);
int process_builtin(char **line, int c);
int ch_dir(char **line, __attribute__((unused))int c);
/**
 * print_env - Function to print env
 * @line: pointer to comd
 * @s: line status
 * Return: 0 always
 */
int print_env(__attribute__((unused)) char **line,
		__attribute__((unused)) int s);
int echo_handler(char **line, int c);
void my_exit(char **line, char *run, char **argv, int n, int s);
/**
 * echo_history - Function to Echo History
 * @run: Command line
 * @ch: command status
 * Return: Always 0
 */
int echo_history(__attribute__((unused))char **run,
		__attribute__((unused))int ch);

/********************HISTORY*********************/
int dis_history(char *line);

/*******************READ FIILE*******************/
void file_reader(char *f, char **argv);
void run_file(char *cmd, int c, FILE *fl, char **argv);
void exit_file(char **cmd, char *input, FILE *fl);

/*****************MEMORY***************************/
void free_me(char **input, char *run);
void *my_realloc(void *point, unsigned int old_s, unsigned int new_s);
char *my_memcpy(char *tmp, char *input, unsigned int num);
void *mem_arr(void *prt, int num, unsigned int run);
void *my_calloc(unsigned int value);

void env_mem_free(char **input);
void make_env(char **line);

/****************CHAR FUNCTIONS*********************/
int my_strlen(char *str);
int _putchar(char c);
char *my_strncpy(char *dst, char *sc, int n);
void my_puts(char *stri);
int my_atoi(char *st);
char *my_strtok(char *st, const char *tk);
unsigned int check_my_delim(char s, const char *st);

int my_intlen(int n);
void my_arr_rev(char *ar, int m);
char *my_itoa(unsigned int num);
int my_isalpha(int s);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char *buf, char *sc);
char *my_strcat(char *dest, char *sr);
int my_strncmp(const char *str1, const char *str2, size_t num);
char *my_strdup(char *st);
char *my_strchr(char *str, char s);

/**
 *struct my_shell - Structure for Builtin cmd
 *@cmd: Pointer to command
 *@func: Pointer to function
 */
typedef struct my_shell
{
	char *cmd;
	int (*func)(char **run, int c);
} builtincmd;

/*******************DISPLAY************************/
void dis_int(int num);
void dis_num(unsigned int num);
int dis_echo(char **line);

/*****************PATH FINDER************************/
char *create_cmd(char *input, char *toatal);
char *my_getenv(char *env);
int find_path(char **command);
char *my_getline();

/*****************COMMAND FUNCTIONS*******************/
int exec_cmd(char **input, char *run, int s, char **argv);
void handle_signal(int check);
void prompt(void);
char **sep_handler(char *cmd);
char **run_cmd(char *line);

char *my_ent(char *str);
char *my_space(char *st);
void my_hash(char *tmp);

#endif
