#include "libft_tester.h"

int main()
{
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

    char Test_cases[5][40];
    strcpy(Test_cases[0], "");
    strcpy(Test_cases[1], "1337");
    strcpy(Test_cases[2], "future is loading");
    strcpy(Test_cases[3], "we are samurai the keyboard cowboys");
    strcpy(Test_cases[4], "it seems impossible until it's done");

    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 5;

    for (int i = 0; i <= 4; i++)
    {
        // print test case number
        ft_wait(500);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_test_case_string(Test_cases[i]);
        printf("\n");

        size_t your_output = ft_strlen(Test_cases[i]); 
        size_t expected_output = strlen(Test_cases[i]);

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
        {
            count_correct_ans++;
            printf("✅\n");
        }
        else
            printf("❌\n");
    }
    print_last_line();
    print_result(count_correct_ans, number_of_test_cases);
    return (0);
}
