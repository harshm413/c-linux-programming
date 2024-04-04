//Create a pthread program to find the length
//of the string passed to the thread function

#include<stdio.h>
#include<pthread.h>
#include<string.h>

void* stringLength(void* arg){
    char* str=(char*)arg;
    int length=strlen(str);
    printf("Length of the string: %d\n",length);
    pthread_exit(NULL);
}
int main(){
    pthread_t tid;
    char str[]="Hello World";
    pthread_create(&tid,NULL,stringLength,(void*)str);
    pthread_join(tid,NULL);
}