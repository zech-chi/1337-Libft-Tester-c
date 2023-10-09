#include "libft_tester.h"

struct Test {
    char *s1;
    char *s2;
    char *expected;
};

int main()
{
    struct Test Test_cases[11];

    // test_case 1
    Test_cases[0].s1 = strdup("");
    Test_cases[0].s2 = strdup("");
    Test_cases[0].expected = strdup("");

    // test_case 2
    Test_cases[1].s1 = strdup("");
    Test_cases[1].s2 = strdup("world");
    Test_cases[1].expected = strdup("world");

    // test_case 3
    Test_cases[2].s1 = strdup("hello");
    Test_cases[2].s2 = strdup("");
    Test_cases[2].expected = strdup("hello");

    // test_case 4
    Test_cases[3].s1 = strdup("hello ");
    Test_cases[3].s2 = strdup("world");
    Test_cases[3].expected = strdup("hello world");

    // test_case 5
    Test_cases[4].s1 = strdup("1337 ");
    Test_cases[4].s2 = strdup("future is loading");
    Test_cases[4].expected = strdup("1337 future is loading");

    // test_case 6
    Test_cases[5].s1 = strdup("git add, git com");
    Test_cases[5].s2 = strdup("mit, git push");
    Test_cases[5].expected = strdup("git add, git commit, git push");

    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

    print_my_header();

    for (int i = 0; i < 6; i++)
    {
        // print test case number
        wait(700);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_string("s1 = ");
        print_test_case_string(Test_cases[i].s1);
        printf(", ");
        print_string("s2 = ");
        print_test_case_string(Test_cases[i].s2);
        printf("\n");

        // you're output
        char *your_output = ft_strjoin(Test_cases[i].s1, Test_cases[i].s2);
        // diff 
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
    for (int i = 0; i < 6; i++)
    {
        free(Test_cases[i].s1);
        free(Test_cases[i].s2);
    }
    return (0);
}