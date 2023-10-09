#include "libft_tester.h"

int main()
{
    char Test_cases[8][50];
    strcpy(Test_cases[0], "");
    strcpy(Test_cases[1], "1337");
    strcpy(Test_cases[2], "1337 future is loading");
    strcpy(Test_cases[3], "we are samurai the keyboard cowboys");
    strcpy(Test_cases[4], "it seems impossible until it's done");
    strcpy(Test_cases[5], "1,000$");
    strcpy(Test_cases[6], "1,000,000$");
    strcpy(Test_cases[7], "1,000,000,000$");

    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 8;

    for (int i = 0; i < 8; i++)
    {
        // print test case number
        wait(500);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_test_case_string(Test_cases[i]);
        printf("\n");

        char *your_output = ft_strdup(Test_cases[i]);
        char *expected_output = strdup(Test_cases[i]);
        int diff = strcmp(your_output, expected_output);

        // print your output
        print_symbol();
        printf(" your output     : ");
        if (diff == 0)
            print_string_output(your_output, green_color);
        else
            print_string_output(your_output, red_color);
        printf("\n");
        //wait(400);

        // print expect output
        print_symbol();
        printf(" expected output : ");
        print_string_output(expected_output, green_color);
        printf("\n");
        //wait(300);

        // status ✅ or ❌
        print_symbol();
        printf(" status          : ");
        if (diff == 0)
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