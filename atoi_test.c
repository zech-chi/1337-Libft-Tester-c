#include "libft_tester.h"


int main()
{
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";
    char orange_color[] = "\x1b[38;5;208m";
    char close_color[] = "\x1b[0m";


    char Test_cases[14][35];
    
    // test_case 1
    strcpy(Test_cases[0], "");

    // test_case 2
    strcpy(Test_cases[1], " 1337");

    // test_case 3
    strcpy(Test_cases[2]," 0001337");

    // test_case 4
    strcpy(Test_cases[3], " -42");

    // test_case 5
    strcpy(Test_cases[4], " +42");

    // test_case 6
    strcpy(Test_cases[5], " --42");

    // test_case 7
    strcpy(Test_cases[6], " ++42");

    // test_case 8
    strcpy(Test_cases[7], " -+42");

    // test_case 9
    strcpy(Test_cases[8], " +-42");

    // test_case 10
    strcpy(Test_cases[9], "     +---+--+7");

    // test_case 11
    strcpy(Test_cases[10], "2147483647");

    // test_case 12
    strcpy(Test_cases[11], "-2147483648");

    // test_case 13
    strcpy(Test_cases[12], "999999999999999");

    // test_case 14
    strcpy(Test_cases[13], " \t\n\v\f\r  1337 future is loading");
    
    print_my_header();

    for (int i = 0; i < 14; i++)
    {
        // print test case number
        wait(700);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_printable_and_nonprintable_test_case(Test_cases[i]);
        printf("\n");

        // this is your output
        int your_output = ft_atoi(Test_cases[i]);
        // expected output by original atoi function
        int expected_output = atoi(Test_cases[i]);

        // print your output
        print_symbol();
        printf(" your output     : ");
        if (your_output == expected_output)
            print_int_output(your_output, green_color);
        else
            print_int_output(your_output, red_color);
        printf("\n");
        //wait(400);

        // print expect output
        print_symbol();
        printf(" expected output : ");
        print_int_output(expected_output, green_color);
        printf("\n");
        //wait(300);

        // status ✅ or ❌
        print_symbol();
        printf(" status          : ");
        if (your_output == expected_output)
            printf("✅\n");
        else
            printf("❌\n");
    }
    print_last_line();
    printf("\n⚠️  %s(9) = \\t | (10) = \\n | (11) = \\v | (12) = \\f | (13) = \\r%s\n", orange_color, close_color);
    return (0);
}