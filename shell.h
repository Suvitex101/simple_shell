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

#endif
