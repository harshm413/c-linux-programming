// Write a C program to illustrate that performing 
// 'n' consecutive fork() system calls generates a total 
// of 2^n-1 child processes. The program should prompt 
// the user to input the value of 'n'.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("Generating %d forks...\n",n);
    for(int i=0;i<n;++i){
        if(fork()==0){
            printf("Child process\n");
        }
    }
    for(int i=0;i<n;++i){
        wait(NULL);
    }
}