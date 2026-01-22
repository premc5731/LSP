#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

#define MAXTEXT 512

struct MarvellousMessage
{
    long int msg_type;
    char data[MAXTEXT];
};

int main()
{
    int iRet = 0;
    key_t key;
    int id = 0;
    struct MarvellousMessage mobj;

    key = ftok(".", 'a');

    id = msgget(key, 0666);

    if(id == -1)
    {
        printf("Unable to allocate message queue\n");
        return -1;
    }

    iRet = msgrcv(id, (void *)&mobj, MAXTEXT, 11, IPC_NOWAIT);

    if(iRet > 0)
    {
        printf("Data received from message : %s",mobj.data);
    }

    iRet = msgrcv(id, (void *)&mobj, MAXTEXT, 12, IPC_NOWAIT);

    if(iRet > 0)
    {
        printf("Data received from message : %s",mobj.data);
    }

    return 0;
}