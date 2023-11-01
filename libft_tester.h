#ifndef LIBFT_TESTER_H
#define LIBFT_TESTER_H

#include <fcntl.h>
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
void ft_wait(int ms);
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
char 	**ft_split(char const *s, char c);
int 	ft_atoi(const char *nptr);
char 	*ft_itoa(int n);
char 	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_strtrim(char const *s1, char const *set);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
int 	ft_isprint(int c);
size_t 	ft_strlen(const char *s);
char    *ft_strdup(const char *s);
int 	ft_tolower(int c);
int 	ft_toupper(int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int 	ft_isalpha(int c);
int		ft_isascii(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);

#endif
