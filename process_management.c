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
printf("\n\tHello");
printf("\n\tI am EXEC.c called by execvp()");
printf("\n\tIn fork command");
a=fork();
if (a>0)
{
printf("\n\tParent pid is: %d", getpid());
printf("\n\tParent ppid is: %d", getppid());
}
if (a==0)
{
printf("\n\tChild pid is: %d", getpid());
printf("\n\tChild ppid is: %d", getppid());
}
printf("\n\tWork Done");
sleep(4);
printf("\n\tWork Accomplished");
return 0;
}
