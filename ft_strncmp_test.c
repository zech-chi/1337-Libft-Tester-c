#include "libft_tester.h"

struct Test {
    char *s1;
    char *s2;
    int n;
};

int main()
{
    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 11;
    struct Test Test_cases[number_of_test_cases];
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";
    char orange_color[] = "\x1b[38;5;208m";
    char close_color[] = "\x1b[0m";

    // test_case 1
    Test_cases[0].s1 = strdup("hello world");
    Test_cases[0].s2 = strdup("hello");
    Test_cases[0].n = 0;

    // test_case 2
    Test_cases[1].s1 = strdup("hello world");
    Test_cases[1].s2 = strdup("hello");
    Test_cases[1].n = 5;

    // test_case 3
    Test_cases[2].s1 = strdup("hello world");
    Test_cases[2].s2 = strdup("hello");
    Test_cases[2].n = 6;

    // test_case 4
    Test_cases[3].s1 = strdup("hello world");
    Test_cases[3].s2 = strdup("hello");
    Test_cases[3].n = 7;

    // test_case 5
    Test_cases[4].s1 = strdup("");
    Test_cases[4].s2 = strdup("");
    Test_cases[4].n = 0;

    // test_case 6
    Test_cases[5].s1 = strdup("");
    Test_cases[5].s2 = strdup("");
    Test_cases[5].n = 1;

    // test_case 7
    Test_cases[6].s1 = strdup("");
    Test_cases[6].s2 = strdup("hello");
    Test_cases[6].n = 0;

    // test_case 8
    Test_cases[7].s1 = strdup("");
    Test_cases[7].s2 = strdup("hello");
    Test_cases[7].n = 2;

    // test_case 9
    Test_cases[8].s1 = strdup("1337");
    Test_cases[8].s2 = strdup("1337");
    Test_cases[8].n = 3;

    // test_case 10
    Test_cases[9].s1 = strdup("1337");
    Test_cases[9].s2 = strdup("1337");
    Test_cases[9].n = 42;

    // test_case 11
    Test_cases[10].s1 = strdup("1337 the best school");
    Test_cases[10].s2 = strdup("1337 future is loading");
    Test_cases[10].n = 1337;

    for (int i = 0; i < 11; i++)
    {
        // print test case number
        ft_wait(400);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_string("s1 = ");
        print_test_case_string(Test_cases[i].s1);
        printf(", ");
        print_string("s2 = ");
        print_test_case_string(Test_cases[i].s2);
        printf(", ");
        printf("%sn = %s", orange_color, close_color);
        print_test_case_int(Test_cases[i].n);
        printf("\n");

        int your_output = ft_strncmp(Test_cases[i].s1, Test_cases[i].s2, Test_cases[i].n);
        int expected_output = strncmp(Test_cases[i].s1, Test_cases[i].s2, Test_cases[i].n);

        // print your output
        print_symbol();
        printf(" your output      : ");
        if (your_output == expected_output)
            print_int_output(your_output, green_color);
        else
            print_int_output(your_output, red_color);
        printf("\n");
        //wait(400);

        // print expect output
        print_symbol();
        printf(" expected output  : ");
        print_int_output(expected_output, green_color);
        printf("\n");
        //wait(300);

        // status ✅ or ❌
        print_symbol();
        printf(" status           : ");
        if (your_output == expected_output)
        {
            count_correct_ans++;
            printf("✅\n");
        }
        else
        {
            printf("❌\n");
        }
    }
    print_last_line();
    print_result(count_correct_ans, number_of_test_cases);
    // free the allocated memory
    for (int i = 0; i < 11; i++) {
        free(Test_cases[i].s1);
        free(Test_cases[i].s2);
    }
    return (0);
}
