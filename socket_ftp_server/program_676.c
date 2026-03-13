#include <stdio.h>

int main(int argc , char * argv[])
{
    printf("Number of command line arguments are : %d\n",argc);

    if(argc != 5)
    {
        printf("ERROR : unable to proceed as invalid number of arguments \n ");
        printf("Please provide : \n");
        printf("Ip address\nPort number\nTargeted file name\nNew filename\n");

        return -1;
    }

    printf("Executable name : %s\n",argv[0]);
    printf("Ip address : %s\n",argv[1]);
    printf("Port number : %s\n",argv[2]);
    printf("Targeted file : %s\n",argv[3]);
    printf("New file name : %s\n",argv[4]);
    return 0;
}