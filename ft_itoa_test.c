#include "libft_tester.h"

struct Test {
    char *s;
    int n;
};

int main()
{
    struct Test Test_cases[8];

    // test_case 1
    Test_cases[0].s = strdup("0");
    Test_cases[0].n = 0;

    // test_case 2
    Test_cases[1].s = strdup("1");
    Test_cases[1].n = 1;

    // test_case 3
    Test_cases[2].s = strdup("-1");
    Test_cases[2].n = -1;

    // test_case 4
    Test_cases[3].s = strdup("42");
    Test_cases[3].n = 42;
    
    // test_case 5
    Test_cases[4].s = strdup("1337");
    Test_cases[4].n = 1337;

    // test_case 6
    Test_cases[5].s = strdup("-4011");
    Test_cases[5].n = -4011;

    // test_case 7
    Test_cases[6].s = strdup("-2147483648");
    Test_cases[6].n = -2147483648;
    
    // test_case 8
    Test_cases[7].s = strdup("2147483647");
    Test_cases[7].n = 2147483647;

    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

    print_my_header();

    for (int i = 0; i < 8; i++)
    {
        // print test case number
        wait(700);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_test_case_int(Test_cases[i].n);
        printf("\n");

        // this is your output
        char *your_output = ft_itoa(Test_cases[i].n);
        // this is the differcence between expected and what we got
        int diff = strcmp(your_output, Test_cases[i].s);

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
        print_string_output(Test_cases[i].s, green_color);
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
    // free the allocated memory
    for (int i = 0; i < 8; i++) {
        free(Test_cases[i].s);
    }
    return (0);
}