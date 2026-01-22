#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void * Demo(void *p)
{
    int iSum = 0;
    int *ptr = NULL;

    printf("Inside thread with value \n");

    iSum = (*(((int *)p)+0)) + *(((int *)p)+1) + (*(((int *)p)+2)) + (*(((int *)p)+3));

    ptr = (int *)malloc(sizeof(int));

    *ptr = iSum;

    pthread_exit(ptr);
}

int main()
{
    pthread_t TID;
    int iRet = 0;
    int * Value = 0;
    int Arr[] = {11,21,51,101};

    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID,       // Thread id
                            NULL,       // Thread attributes
                            Demo,       // Thread callback function
                            (int *)Arr  // parameters for the call back function
                        );      
    
    if(iRet == 0)
    {
        printf("Thread created successfully with TID : %lu \n",(unsigned long)TID);

    }


    //main ko wait kara
    pthread_join(TID, &Value);

    printf("Summation is : %d\n",(*Value));

    printf("End of Main thread\n");

    return 0;
}