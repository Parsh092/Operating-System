#include <stdio.h>
#include<unistd.h>
int main()
{
    pid_t ret_value;
    printf("\nThe process id is %d: ", pid_t);
    ret_value = fork();
    if (ret_value < 0)
    {
        printf("\n Fork failure");
    }
    else if (ret_value == 0)
    {
        printf("\nChild process");
        printf("\nThe process id is: %d", getpid());
    }
    else
    {
        printf("\nParent process");
        printf("\nThe process id is: %d", getpid());
    }
}