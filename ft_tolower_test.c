#include "libft_tester.h"


int main()
{
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 128;

    for (int i = 0; i <= 127; i++)
    {
        // print test case number
        //wait(300);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case (ascii): ");
        print_test_case_int(i);
        printf("\n");

        int your_output = ft_tolower(i);
        int expected_output = tolower(i);

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
    return (0);
}