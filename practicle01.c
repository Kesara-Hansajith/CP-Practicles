#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_msg(void *msg)    //* use to pointers
{
    char *message;
    message= (char *) msg;
    printf("%s \n", message);

}

void main()
{
    pthread_t thread1,thread2;
    int iret1, iret2;

    char *msg1="Hello from thread 1";
    char *msg2="Hello from thread 2";


    iret1=pthread_create(&thread1,NULL,print_msg,(void *)msg1);
    iret2=pthread_create(&thread2,NULL,print_msg,(void *)msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);

    exit(0);
}
