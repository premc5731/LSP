#include<stdio.h>
#include<pthread.h>


void * Demo(void *p)
{
    printf("Inside thread\n");
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID,       // Thread id
                            NULL,       // Thread attributes
                            Demo,       // Thread callback function
                            NULL        // parameters for the call back function
                        );      
    
    if(iRet == 0)
    {
        printf("Thread created successfully\n");

    }

    
    printf("End of Main thread\n");

    return 0;
}