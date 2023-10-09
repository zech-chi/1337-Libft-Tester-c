#include "libft_tester.h"

struct  Test
{
    char *src;
    size_t size_of_dest;
};

size_t	ft_strlcpy2(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

int main()
{
    char green_color[] = "\x1b[32m";
    char red_color[] = "\x1b[31m";
    char orange_color[] = "\x1b[38;5;208m";
    char close_color[] = "\x1b[0m";


    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 7;


    struct Test Test_cases[number_of_test_cases];

    // test_case 1
    Test_cases[0].src = strdup("Hello, World!");
    Test_cases[0].size_of_dest = 0;

    // test_case 2
    Test_cases[1].src = strdup("Hello, World!");
    Test_cases[1].size_of_dest = 5;

    // test_case 3
    Test_cases[2].src = strdup("Hello, World!");
    Test_cases[2].size_of_dest = 6;

    // test_case 4
    Test_cases[3].src = strdup("Hello, World!");
    Test_cases[3].size_of_dest = 42;

    // test_case 5
    Test_cases[4].src = strdup("It's not about the machine, it's about the data");
    Test_cases[4].size_of_dest = 100;

    // test_case 6
    Test_cases[5].src = strdup("It's not about the machine, it's about the data");
    Test_cases[5].size_of_dest = 100;

    // test_case 7
    Test_cases[6].src = strdup("I hate this msg : segmentation fault");
    Test_cases[6].size_of_dest = 16;

    for (int i = 0; i < number_of_test_cases; i++)
    {
        // print test case number
        wait(300);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_string("src = ");
        print_test_case_string(Test_cases[i].src);
        printf(", ");
        printf("%s", orange_color);
        printf("size_of_dest = ");
        printf("%s", close_color);
        print_test_case_int(Test_cases[i].size_of_dest);
        printf("\n");

        char dest1[Test_cases[i].size_of_dest];
        char dest2[Test_cases[i].size_of_dest];
        size_t res1 = ft_strlcpy(dest1, Test_cases[i].src, sizeof(dest1));
        size_t res2 = ft_strlcpy2(dest2, Test_cases[i].src, sizeof(dest2));
        int diff = strcmp(dest1, dest2);
        diff += res1 - res2;

        // print your output
        print_symbol();
        printf(" your output      : ");
        if (diff == 0)
        {
            printf("%s", green_color);
            printf("dest = ");
            printf("%s", close_color);
            print_string_output(dest1, green_color);
            printf(", ");
            printf("%s", green_color);
            printf("returned_size = ");
            printf("%s", close_color);
            print_int_output(res1, green_color);
            
        }
        else
        {
            printf("%s", red_color);
            printf("dest = ");
            printf("%s", close_color);
            print_string_output(dest1, red_color);
            printf(", ");
            printf("%s", red_color);
            printf("returned_size = ");
            printf("%s", close_color);
            print_int_output(res1, red_color);
        }
        printf("\n");
        //wait(400);

        // print expect output
        print_symbol();
        printf(" expected output  : ");
        printf("%s", green_color);
        printf("dest = ");
        printf("%s", close_color);
        print_string_output(dest1, green_color);
        printf(", ");
        printf("%s", green_color);
        printf("returned_size = ");
        printf("%s", close_color);
        print_int_output(res1, green_color);
        printf("\n");

        // status ✅ or ❌
        print_symbol();
        printf(" status           : ");
        if (diff == 0)
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
    for (int i = 0; i < number_of_test_cases; i++)
    {
        free(Test_cases[i].src);    
    }

}