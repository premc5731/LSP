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

    id = msgget(key, 0666 | IPC_CREAT);

    if(id == -1)
    {
        printf("Unable to allocate message queue\n");
        return -1;
    }

    mobj.msg_type = 11;
    strcpy(mobj.data, "JayGanesh...");

    iRet = msgsnd(id, (void *)&mobj, MAXTEXT, 0);

    if(iRet == 0)
    {
        printf("Message sent succesfully \n");
    }

    mobj.msg_type = 12;
    strcpy(mobj.data, "Pune");

    iRet = msgsnd(id, (void *)&mobj, MAXTEXT, 0);

    if(iRet == 0)
    {
        printf("Message sent succesfully \n");
    }

    return 0;
}