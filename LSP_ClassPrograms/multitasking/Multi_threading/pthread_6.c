#include<stdio.h>
#include<pthread.h>


void * Demo(void *p)
{
    printf("Inside thread with value : %d\n",(int)p);
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;
    int Value = 0;
    int No = 11;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID,       // Thread id
                            NULL,       // Thread attributes
                            Demo,       // Thread callback function
                            (int *)No        // parameters for the call back function
                        );      
    
    if(iRet == 0)
    {
        printf("Thread created successfully with TID : %lu \n",(unsigned long)TID);

    }


    //main ko wait kara
    pthread_join(TID, NULL);

    printf("End of Main thread\n");

    return 0;
}