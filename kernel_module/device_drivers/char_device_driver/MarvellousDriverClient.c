#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/marvellous_driver"
#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    int iRet = 0;
    char read_buffer[BUFFER_SIZE];
    char write_buffer[BUFFER_SIZE];

    printf("Opening the marvellous device...\n");

    // cat /dev/marvellous_driver
    fd = open(DEVICE_PATH, O_RDWR);

    if(fd < 0)
    {
        printf("ERROR: Unable to open Marvellous device : %s\n", strerror(errno));
        return -1;
    }

    printf("Marvellous Device opened successfully\n");

    printf("Enter the data for Marvellous driver\n");
    fgets(write_buffer, BUFFER_SIZE, stdin);

    write_buffer[strcspn(write_buffer, "\n")] = 0;

    printf("Writing to the Marvellous Device\n");

    // echo "Jay Ganesh..." > /dev/marvellous_driver
    iRet = write(fd, write_buffer, strlen(write_buffer));

    if(iRet < 0)
    {
        printf("ERROR: Unable to write into Marvellous device\n");
        close(fd);
        return -1;
    }

    printf("Data successfully written into marvellous driver\n");

    printf("Reading the data from marvellous driver\n");

    // cat /dev/marvellous_driver
    iRet = read(fd, read_buffer, BUFFER_SIZE);
    if(iRet < 0)
    {
        printf("ERROR: Unable to read from Marvellous device\n");
        close(fd);
        return -1;
    }

    read_buffer[iRet] = '\0';

    printf("Data received from marvellous driver : %s\n", read_buffer);

    printf("Closing Marvellous Driver\n");

    close(fd);

    return 0;
}