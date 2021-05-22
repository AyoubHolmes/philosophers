#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
  
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *myThreadFun(void *str)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread.\nArgs: %s\n", str);
    return NULL;
}
   
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, "Hello World");
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}