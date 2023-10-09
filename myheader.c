#include "libft_tester.h"

char green_color[] = "\x1b[32m";
char red_color[] = "\x1b[31m";
char purple_color[] = "\x1b[35m";
char orange_color[] = "\x1b[38;5;208m";
char close_color[] = "\x1b[0m";
char yellow_color[] = "\033[1;33m";

void print_my_header(void)
{
    printf("%s", yellow_color);
    printf("\t\t███████╗███████╗░█████╗░██╗░░██╗░░░░░░░█████╗░██╗░░██╗██╗\n");
    printf("\t\t╚════██║██╔════╝██╔══██╗██║░░██║░░░░░░██╔══██╗██║░░██║██║\n");
    printf("\t\t░░███╔═╝█████╗░░██║░░╚═╝███████║█████╗██║░░╚═╝███████║██║\n");
    printf("\t\t██╔══╝░░██╔══╝░░██║░░██╗██╔══██║╚════╝██║░░██╗██╔══██║██║\n");
    printf("\t\t███████╗███████╗╚█████╔╝██║░░██║░░░░░░╚█████╔╝██║░░██║██║\n");
    printf("\t\t╚══════╝╚══════╝░╚════╝░╚═╝░░╚═╝░░░░░░░╚════╝░╚═╝░░╚═╝╚═╝\n\n");
    printf("%s", close_color);
    wait(700);
}

void print_test_number(int n)
{
    char c1 = '-';
    char c2 = '$';
    char c3 = '$';
    printf("%s", yellow_color);
    for (int i = 0; i < 40; i++)
        printf("%c", c1);
    printf("%c ", c2);
    printf("test %d ", n);
    printf("%c", c3);
    for (int i = 0; i < 40; i++)
        printf("%c", c1);
    printf("\n%s", close_color);
}

void print_last_line(void)
{
    char c = '-';
    printf("%s", yellow_color);
    for (int i = 0; i < 90; i++)
        printf("%c", c);
    printf("\n%s", close_color);
}

void print_symbol(void)
{
    char c = '$';
    printf("%s", yellow_color);
    printf("%c", c);
    printf("%s", close_color);
}

void wait(int ms)
{
    usleep(ms * 1000);
}

void print_array_of_strings_output(char **av, char *color)
{
    printf("%s", color);
    printf("[");
    int i = 0;
    while (av[i])
    {
        if (i != 0)
            printf(",");
        printf("\"%s\"", av[i]);
        i++;
    }
    printf("]\n");
    printf("%s", close_color);
}

void print_test_case_string(char *str)
{
    printf("%s", purple_color);
    printf("\"%s\"", str);
    printf("%s", close_color);
}

void print_test_case_char(char c)
{
    printf("%s", purple_color);
    printf("'%c'", c);
    printf("%s", close_color);
}

void print_test_case_int(int n)
{
    printf("%s", orange_color);
    printf("%d", n);
    printf("%s", close_color);
}

void print_string(char *str)
{
    printf("%s", purple_color);
    printf("%s", str);
    printf("%s", close_color);
}

void print_int_output(int n, char *color)
{
    printf("%s", color);
    printf("%d", n);
    printf("%s", close_color);
}

void print_string_output(char *str, char *color)
{
    printf("%s", color);
    printf("\"%s\"", str);
    printf("%s", close_color);
}


void print_printable_and_nonprintable_test_case(char *str)
{
    int j = 0;
    printf("%s", purple_color);
    printf("\"");
    printf("%s", close_color);
    while (str[j])
    {
        if (' ' <= str[j] && str[j] <= '~')
            printf("%s%c%s", purple_color, str[j], close_color);
        else
            printf("%s(%d)%s", orange_color, str[j], close_color);
        j++;
    }
    printf("%s", purple_color);
    printf("\"");
    printf("%s", close_color);
}

void print_result(int count_correct_ans, int total_test_cases)
{
    if (count_correct_ans == total_test_cases)
    {
        printf("%s", green_color);
        printf("all tests passed successfuly 100%%");
        printf(" ✅\n\n");
        printf("%s", close_color);
    }
    else 
    {
        printf("%s", red_color);
        printf("%d passed from %d tests", count_correct_ans, total_test_cases);
        printf(" ❌\n");
        printf("%s", red_color);
    }
}