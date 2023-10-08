#include "libft_tester.h"


struct  Test
{
    char *s;
    char c;
    char **expected;
};


int main()
{
    struct Test Test_cases[9];

    // test_case 1
    Test_cases[0].s = strdup("hello world");
    Test_cases[0].c = ' ';
    Test_cases[0].expected = malloc(3 * sizeof(char *));
    Test_cases[0].expected[0] = strdup("hello");
    Test_cases[0].expected[1] = strdup("world");
    Test_cases[0].expected[2] = NULL;

    // test_case 2
    Test_cases[1].s = strdup("+hello+world+");
    Test_cases[1].c = '+';
    Test_cases[1].expected = malloc(3 * sizeof(char *));
    Test_cases[1].expected[0] = strdup("hello");
    Test_cases[1].expected[1] = strdup("world");
    Test_cases[1].expected[2] = NULL;

    // test_case 3
    Test_cases[2].s = strdup("***1337**future****is***loading********");
    Test_cases[2].c = '*';
    Test_cases[2].expected = malloc(5 * sizeof(char *));
    Test_cases[2].expected[0] = strdup("1337");
    Test_cases[2].expected[1] = strdup("future");
    Test_cases[2].expected[2] = strdup("is");
    Test_cases[2].expected[3] = strdup("loading");
    Test_cases[2].expected[4] = NULL;

    // test_case 4
    Test_cases[3].s = strdup("$$$money is power");
    Test_cases[3].c = '$';
    Test_cases[3].expected = malloc(2 * sizeof(char *));
    Test_cases[3].expected[0] = strdup("money is power");
    Test_cases[3].expected[1] = NULL;

    // test_case 5
    Test_cases[4].s = strdup("money is power$$$");
    Test_cases[4].c = '$';
    Test_cases[4].expected = malloc(2 * sizeof(char *));
    Test_cases[4].expected[0] = strdup("money is power");
    Test_cases[4].expected[1] = NULL;

    // test_case 6
    Test_cases[5].s = strdup("$$$money is power$$$");
    Test_cases[5].c = '$';
    Test_cases[5].expected = malloc(2 * sizeof(char *));
    Test_cases[5].expected[0] = strdup("money is power");
    Test_cases[5].expected[1] = NULL;

    // test_case 7
    Test_cases[6].s = strdup("42 network");
    Test_cases[6].c = '0';
    Test_cases[6].expected = malloc(2 * sizeof(char *));
    Test_cases[6].expected[0] = strdup("42 network");
    Test_cases[6].expected[1] = NULL;

    // test_case 8
    Test_cases[7].s = strdup("");
    Test_cases[7].c = '#';
    Test_cases[7].expected = malloc(1 * sizeof(char *));
    Test_cases[7].expected[0] = NULL;

    // test_case 9
    Test_cases[8].s = strdup("############################");
    Test_cases[8].c = '#';
    Test_cases[8].expected = malloc(1 * sizeof(char *));
    Test_cases[8].expected[0] = NULL;

    // char color[15];

    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

    print_my_header();

    for (int i = 0; i < 9; i++)
    {
        wait(500);
        print_test_number(i + 1);

        print_symbol();
        printf(" test case       : ");
        print_string("s = ");
        print_test_case_string(Test_cases[i].s);
        printf(", ");
        print_string("c = ");
        print_test_case_char(Test_cases[i].c);
        printf("\n");

        char **your_output = ft_split(Test_cases[i].s, Test_cases[i].c);
        int diff = 0;
        int j1 = 0;
        int j2 = 0;

        while (your_output[j1] && Test_cases[i].expected[j2])
            diff += strcmp(your_output[j1++], Test_cases[i].expected[j2++]);
        if (your_output[j1])
            diff = 1;
        if (Test_cases[i].expected[j2])
            diff = 1;


        print_symbol();
        printf(" your output     : ");
        if (diff == 0)
            print_array_of_strings_output(your_output, green_color);
        else
            print_array_of_strings_output(your_output, red_color);

        //wait(400);

        print_symbol();
        printf(" expected output : ");
        print_array_of_strings_output(Test_cases[i].expected, green_color);

        //wait(300);

        print_symbol();
        printf(" status          : ");
        if (diff == 0)
            printf("✅\n");
        else
            printf("❌\n");
    }
    print_last_line();
    for (int i = 0; i < 9; i++)
    {
        free(Test_cases[i].s);
        int j = 0;
        while (Test_cases[i].expected[j])
            free(Test_cases[i].expected[j++]);
    }
}
