#include "libft_tester.h"

char *ft_strtrim(char const *s1, char const *set);

struct  Test
{
    char *s1;
    char *set;
    char *expected;
};

int main()
{
    int Test_cases_size = 8;
    struct Test Test_cases[Test_cases_size];

    // test case 1
    Test_cases[0].s1 = strdup("+_+");
    Test_cases[0].set = strdup("+");
    Test_cases[0].expected = strdup("_");

    // test case 2
    Test_cases[1].s1 = strdup("+_+----------");
    Test_cases[1].set = strdup("-");
    Test_cases[1].expected = strdup("+_+");

    // test case 3
    Test_cases[2].s1 = strdup("----------+_+");
    Test_cases[2].set = strdup("-");
    Test_cases[2].expected = strdup("+_+");

    // test case 4
    Test_cases[3].s1 = strdup("----------+_+----------");
    Test_cases[3].set = strdup("-");
    Test_cases[3].expected = strdup("+_+");

    // test case 5
    Test_cases[4].s1 = strdup("----------+_+----------");
    Test_cases[4].set = strdup("");
    Test_cases[4].expected = strdup("----------+_+----------");

    // test case 6
    Test_cases[5].s1 = strdup("<<<---<..>-<...><<+_+**#~=");
    Test_cases[5].set = strdup("<.->*#~=");
    Test_cases[5].expected = strdup("+_+");

    // test case 7
    Test_cases[6].s1 = strdup(" 1337 future is loading            ");
    Test_cases[6].set = strdup(" ");
    Test_cases[6].expected = strdup("1337 future is loading");

    // test case 8
    Test_cases[7].s1 = strdup("\t1337 future is loading\n");
    Test_cases[7].set = strdup("\t\n");
    Test_cases[7].expected = strdup("1337 future is loading");

    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";
    char orange_color[] = "\x1b[38;5;208m";
    char close_color[] = "\x1b[0m";

    print_my_header();

    for (int i = 0; i < Test_cases_size; i++)
    {
        // print test case number
        wait(700);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_string("s1 = ");
        print_printable_and_nonprintable_test_case(Test_cases[i].s1);
        printf(", ");
        print_string("set = ");
        print_printable_and_nonprintable_test_case(Test_cases[i].set);
        printf("\n");

        char *your_output = ft_strtrim(Test_cases[i].s1, Test_cases[i].set);
        int diff = strcmp(your_output, Test_cases[i].expected);


        // print your output
        print_symbol();
        printf(" your output     : ");
        if (diff)
            print_string_output(your_output, red_color);
        else
            print_string_output(your_output, green_color);
        printf("\n");
        //wait(400);

        // print expect output
        print_symbol();
        printf(" expected output : ");
        print_string_output(Test_cases[i].expected, green_color);
        printf("\n");
        //wait(300);

        // status ✅ or ❌
        print_symbol();
        printf(" status          : ");
        if (diff)
            printf("❌\n");
        else
            printf("✅\n");

    }
    print_last_line();
    printf("\n⚠️ ⚠️ ⚠️  %s(9) = '\\t' | (10) = '\\n'%s\n", orange_color, close_color);


    for (int i = 0; i < Test_cases_size; i++)
    {
        free(Test_cases[i].s1);
        free(Test_cases[i].set);
        free(Test_cases[i].expected);
    }
    return (0);
}
