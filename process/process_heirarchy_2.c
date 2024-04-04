// Write a C program utilizing the fork() system 
// call to generate the following process hierarchy: 
// P1 -> P2, P1 -> P3, P2 -> P4 -> P5. The program should display the 
// Process ID (PID) and Parent Process IDs (PPID) 
// for each process created.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
   printf("P1 (PID: %d, PPID: %d) is the initial process.\n",getpid(),getppid());
   pid_t pid3=fork();
   if(pid3==0){
       printf("P3 (PID: %d, PPID: %d)\n",getpid(),getppid());
   }else{
       pid_t pid2=fork();
       if(pid2==0){
           printf("P2 (PID: %d, PPID: %d)\n",getpid(),getppid());
           pid_t pid4=fork();
           if(pid4==0){
               printf("P4 (PID: %d, PPID: %d)\n",getpid(),getppid());
               pid_t pid5=fork();
               if(pid5==0){
                   printf("P5 (PID: %d, PPID: %d)\n",getpid(),getppid());
               }
           }
       }
   }
   wait(NULL);
   wait(NULL);
   wait(NULL);
   wait(NULL);
}