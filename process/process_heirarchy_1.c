// Write a C program utilizing the fork() system 
// call to generate the following process hierarchy: 
// P1 -> P2 -> P3. The program should display the 
// Process ID (PID) and Parent Process IDs (PPID) 
// for each process created.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
   printf("P1 (PID: %d, PPID: %d) is the initial process.\n",getpid(),getppid());
   pid_t pid=fork();
   if(pid==0){
       printf("P2 (PID: %d, PPID: %d) is the child of P1.\n",getpid(),getppid());
       pid_t pid2=fork();
       if(pid2==0){
           printf("P3 (PID: %d, PPID: %d) is the child of P2.\n",getpid(),getppid());
       }
   }
   wait(NULL);
   wait(NULL);
}