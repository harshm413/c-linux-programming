// Develop a program using pthread to concatenate 
// multiple strings passed to the thread function.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define MAX_STRINGS 5
#define MAX_LENGTH 100
void* concatenateStrings(void* arg){
    char** strings=(char**)arg;
    char result[MAX_LENGTH*MAX_STRINGS]="";
    for(int i=0;i<MAX_STRINGS;++i){
        strcat(result,strings[i]);
    }
    printf("Concatenated string: %s\n",result);
    pthread_exit(NULL);
}
int main(){
   pthread_t tid;
   char* strings[MAX_STRINGS]={
       "Hello","from","the","thread","function"
   };
   pthread_create(&tid,NULL,concatenateStrings,(void*)strings);
   pthread_join(tid,NULL);
}