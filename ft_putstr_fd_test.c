#include "libft_tester.h"

void ft_putstr_fd(char *s, int fd);

int main()
{
    print_my_header();
    int count_correct_ans = 0;
    int number_of_test_cases = 5;

    char Test_cases[number_of_test_cases][40];
    strcpy(Test_cases[0], "");
    strcpy(Test_cases[1], "1337");
    strcpy(Test_cases[2], "future is loading");
    strcpy(Test_cases[3], "we are samurai the keyboard cowboys");
    strcpy(Test_cases[4], "it seems impossible until it's done");


    const char *basePathgot = "./files_test_ft_putstr_fd/got/";
    const char *basePathexpected = "./files_test_ft_putstr_fd/expected/";

    for (int i = 0; i < number_of_test_cases; i++)
    {
        // print test case number
        //wait(300);
        print_test_number(i + 1);

        // print test case
        print_symbol();
        printf(" test case       : ");
        print_test_case_string(Test_cases[i]);
        printf("\n");

        char filePathgot[256];  // Adjust the size as needed
        snprintf(filePathgot, sizeof(filePathgot), "%stest%d_got.txt", basePathgot, i + 1);

        char touch_command[300];  // Adjust the size as needed
        snprintf(touch_command, sizeof(touch_command), "touch %s", filePathgot);

        char rm_command[300];
        snprintf(rm_command, sizeof(rm_command), "rm %s", filePathgot);

        if (access(filePathgot, F_OK) == 0) {
            system(rm_command);
        }
        system(touch_command);

        int fd = open(filePathgot, O_RDWR);
        ft_putstr_fd(Test_cases[i], fd);

        char filePathexpected[256];
        snprintf(filePathexpected, sizeof(filePathexpected), "%stest%d.txt", basePathexpected, i + 1);

        char diff_command[600];
        snprintf(diff_command, sizeof(diff_command), "diff %s %s", filePathgot, filePathexpected);

        int diff = system(diff_command);

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