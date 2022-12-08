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
