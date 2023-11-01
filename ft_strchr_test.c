#include "libft_tester.h"

struct Test {
	char *s;
	char c;
};


int main()
{
	print_my_header();
	int count_correct_ans = 0;
	int number_of_test_cases = 10;
	struct Test Test_cases[number_of_test_cases];
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";

	// test_case 1
    Test_cases[0].s = strdup("");
    Test_cases[0].c = 'x';

	// test_case 2
    Test_cases[1].s = strdup("hello world");
    Test_cases[1].c = 'o';

	// test_case 3
    Test_cases[2].s = strdup("hello world");
    Test_cases[2].c = 'h';

	// test_case 4
    Test_cases[3].s = strdup("1337 future is loading");
    Test_cases[3].c = '3';

	// test_case 5
    Test_cases[4].s = strdup("1337 future is loading");
    Test_cases[4].c = 'y';

	// test_case 6
    Test_cases[5].s = strdup("it always seems impossible until it's done");
    Test_cases[5].c = '\'';


	// test_case 7
    Test_cases[6].s = strdup("it always seems impossible until it's done");
    Test_cases[6].c = 'u';

	// test_case 8
    Test_cases[7].s = strdup("git add git commit git push");
    Test_cases[7].c = 'g';

	// test_case 9
    Test_cases[8].s = strdup("The way to get started is to quit talking and begin doing");
    Test_cases[8].c = 'g';

	// test_case 10
    Test_cases[9].s = strdup("byte kilobyte megabyte gigabyte terabyte");
    Test_cases[9].c = 'a';
	


	for (int i = 0; i < number_of_test_cases; i++)
	{
		// print test case number
        ft_wait(300);
        print_test_number(i + 1);

		// print test case
        print_symbol();
        printf(" test case       : ");
        print_string("s = ");
        print_test_case_string(Test_cases[i].s);
        printf(", ");
        print_string("c = ");
		print_test_case_char(Test_cases[i].c);
        printf("\n");

		char *your_output = ft_strchr(Test_cases[i].s, Test_cases[i].c);
        printf("%s\n", Test_cases[i].s);
		char *expected_output = strchr(Test_cases[i].s, Test_cases[i].c);
		//char *expected_output = "jdk";
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
    // free the allocated memory
    for (int i = 0; i < number_of_test_cases; i++) {
        free(Test_cases[i].s);
    }
    return (0);
}
