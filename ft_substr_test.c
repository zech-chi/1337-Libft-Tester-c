#include "libft_tester.h"

struct Test {
    char *s;
    unsigned int start;
    size_t len;
    char *expected;
};

int main()
{
    struct Test Test_cases[14];

    // test_case 1
    Test_cases[0].s = strdup("");
    Test_cases[0].start = 0;
    Test_cases[0].len = 0;
    Test_cases[0].expected = strdup("");

    // test_case 2
    Test_cases[1].s = strdup("Highlight");
    Test_cases[1].start = 0;
    Test_cases[1].len = 184467440;
    Test_cases[1].expected = strdup("Highlight");

    // test_case 3
    Test_cases[2].s = strdup("Elephant");
    Test_cases[2].start = 0;
    Test_cases[2].len = 1;
    Test_cases[2].expected = strdup("E");
    
    // test_case 4
    Test_cases[3].s = strdup("Apartment");
    Test_cases[3].start = 42;
    Test_cases[3].len = 1;
    Test_cases[3].expected = strdup("");
    
    // test_case 5
    Test_cases[4].s = strdup("0");
    Test_cases[4].start = 1337;
    Test_cases[4].len = 38333;
    Test_cases[4].expected = strdup("");
    
    // test_case 6
    Test_cases[5].s = strdup("0123456789");
    Test_cases[5].start = 9;
    Test_cases[5].len = 10;
    Test_cases[5].expected = strdup("9");
    
    // test_case 7
    Test_cases[6].s = strdup("0123456789");
    Test_cases[6].start = 7;
    Test_cases[6].len = 1;
    Test_cases[6].expected = strdup("7");
    
    // test_case 8
    Test_cases[7].s = strdup("1337");
    Test_cases[7].start = 0;
    Test_cases[7].len = 0;
    Test_cases[7].expected = strdup("");
    
    // test_case 9
    Test_cases[8].s = strdup("1337 future is loading");
    Test_cases[8].start = 0;
    Test_cases[8].len = 4;
    Test_cases[8].expected = strdup("1337");
    
    // test_case 10
    Test_cases[9].s = strdup("1337 future is loading");
    Test_cases[9].start = 5;
    Test_cases[9].len = 17;
    Test_cases[9].expected = strdup("future is loading");
    
    // test_case 11
    Test_cases[10].s = strdup("1337");
    Test_cases[10].start = 1;
    Test_cases[10].len = 2;
    Test_cases[10].expected = strdup("33");
    
    // test_case 12
    Test_cases[11].s = strdup("1337");
    Test_cases[11].start = 2;
    Test_cases[11].len = 1;
    Test_cases[11].expected = strdup("3");
    
    // test_case 13
    Test_cases[12].s = strdup("1337");
    Test_cases[12].start = 2;
    Test_cases[12].len = 2;
    Test_cases[12].expected = strdup("37");
    
    // test_case 14
    Test_cases[13].s = strdup("1337");
    Test_cases[13].start = 2;
    Test_cases[13].len = 42;
    Test_cases[13].expected = strdup("37");

    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";
    char orange_color[] = "\x1b[38;5;208m";
    char close_color[] = "\x1b[0m";

    print_my_header();

    for (int i = 0; i < 14; i++)
    {
        // print test case number
        wait(700);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_string("s = ");
        print_test_case_string(Test_cases[i].s);
        printf(", ");
        printf("%sstart = %s", orange_color, close_color);
        print_test_case_int(Test_cases[i].start);
        printf(", ");
        printf("%slen = %s", orange_color, close_color);
        print_test_case_int(Test_cases[i].len);
        printf("\n");

        char *your_output = ft_substr(Test_cases[i].s, Test_cases[i].start, Test_cases[i].len);
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
    for (int i = 0; i < 14; i++)
    {
        if (Test_cases[i].s)
            free(Test_cases[i].s);
        if (Test_cases[i].expected)
            free(Test_cases[i].expected);
    }
    return (0);
}