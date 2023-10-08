#ifndef LIBFT_TESTER_H
#define LIBFT_TESTER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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





//Libft_functions
//// ft_split
char **ft_split(char const *s, char c);
//// atoi
int ft_atoi(const char *nptr);
//// ft_itoa
char *ft_itoa(int n);


#endif