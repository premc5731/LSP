#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

int icnt = 0;

void * Increment(void * arg)
{
    pthread_mutex_lock(&lock);  // lock lagana

        icnt++;

        printf("%d\n",icnt);

    pthread_mutex_unlock(&lock);    // lock nikalna

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);    // lock lena

    pthread_create(&t1, NULL, Increment, NULL);
    pthread_create(&t2, NULL, Increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock); // lock dena
    
    return 0;
}