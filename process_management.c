// In Terminal
nano p.c
gcc p.c -o p
./p 
-----------------------------------------
// C code
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main (){
   int fd,n;
   char buff[50];
  n=write(0,"Hello",20);
  printf("The value of n is %d\n",n); 
    return 0;
}



// New Code

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
int a;
printf("Hello\n");
printf("I am EXEC.c called by execvp()");
printf("In fork command");
a=fork();
if (a>0)
{
printf("Parent pid is %d\n", getpid());
printf("{arent ppid is %d\n", getppid());
}
if (a==0)
{
printf("Child pid is %d\n", getpid());
printf("Child ppid is %d\n", getppid());
}
printf("Work Done\n");
sleep(4);
printf("Work Accomplished");
return 0;
