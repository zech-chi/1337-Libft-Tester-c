#include "libft_tester.h"



int main()
{
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";
    char purple_color[] = "\x1b[35m";
    char orange_color[] = "\x1b[38;5;208m";
    char close_color[] = "\x1b[0m";

    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 128;

    for (int i = 0; i <= 127; i++)
    {
        // print test case number
        ft_wait(30);
        print_test_number(i + 1);


        // print test case
        print_symbol();
        printf(" ascii           : %d\n", i);
        print_symbol();
        printf(" test case       : ");
        char c = i;
        if (i < 32 || i == 127)
            printf("%snonprintable char%s", orange_color, close_color);
        else
            printf("%s'%c'%s", purple_color, c, close_color);
        printf("\n");

        int your_output = ft_isprint(i);
        int expected_output = isprint(i);
        if (expected_output)
            expected_output = 1;

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
        {
            printf("❌\n");
        }
    }
    print_last_line();
    print_result(count_correct_ans, number_of_test_cases);
    return (0);
}
