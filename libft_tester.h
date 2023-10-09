#ifndef LIBFT_TESTER_H
#define LIBFT_TESTER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

// print my header
void print_my_header(void);
// print current number of test case
void print_test_number(int n);
// the end closing
void print_last_line(void);
// the symbol of starting line
void print_symbol(void);
// wait a few time before the program going on
void wait(int ms);
// output print
void print_array_of_strings_output(char **av, char *color);
void print_int_output(int n, char *color);
void print_string_output(char *str, char *color);
// test case print
void print_test_case_char(char c);
void print_test_case_string(char *str);
void print_test_case_int(int n);
void print_printable_and_nonprintable_test_case(char *str);
// others
void print_string(char *str);
void print_result(int count_correct_ans, int total_test_cases);





//Libft_functions
//// ft_split
char **ft_split(char const *s, char c);
//// atoi
int ft_atoi(const char *nptr);
//// ft_itoa
char *ft_itoa(int n);
//// ft_strjoin
char *ft_strjoin(char const *s1, char const *s2);
//// ft_strtrim
char *ft_strtrim(char const *s1, char const *set);
//// ft_substr
char *ft_substr(char const *s, unsigned int start, size_t len);
//// ft_isprint
int ft_isprint(int c);
//// ft_strlen
size_t ft_strlen(const char *s);
//// ft_strdup
char    *ft_strdup(const char *s);
//// ft_tolower
int ft_tolower(int c);
//// ft_toupper
int ft_toupper(int c);


#endif