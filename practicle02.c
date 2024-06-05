#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *add_num(int num1, int num2)    //* use to pointers
{

    double sum;
    sum = num1+num2;
    printf("The total from thread is : ", sum);

}

void main()
{


    int num1;
    printf("Enter an integer: ");
    scanf("%d", &num1);
    printf("You entered: %d\n", num1);

    int num2;
    printf("Enter an integer: ");
    scanf("%d", &num2);
    printf("You entered: %d\n", num2);

    pthread_t thread1,thread2;
    int iret1, iret2;


    iret1=pthread_create(&thread1,NULL,add_num,(int *)num1);
    iret2=pthread_create(&thread2,NULL,add_num,(int *)num2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    exit(0);
}

