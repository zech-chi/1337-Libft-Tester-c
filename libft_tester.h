#ifndef LIBFT_TESTER_H
#define LIBFT_TESTER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//design
void print_my_header(void);
void print_test_number(int n);
void print_last_line(void);
void print_symbol(void);
void wait(int ms);
void print_array_of_strings_output(char **av, char *color);
void print_test_case_char(char c);
void print_test_case_string(char *str);
void print_string(char *str);
void print_int_output(int n, char *color);
void print_printable_and_nonprintable_test_case(char *str);

//Libft_functions
//// ft_split
char **ft_split(char const *s, char c);
//// atoi
int ft_atoi(const char *nptr);

//Test_functions



#endif