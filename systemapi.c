#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];

    // Open or create a file
    fd = open("demo.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd < 0)
    {
        perror("Open failed");
        return 1;
    }

    // Write data into the file
    write(fd, "Linux System Calls", 18);

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read data from file
    read(fd, buffer, 18);
    buffer[18] = '\0';

    printf("File Content: %s\n", buffer);

    // Display process ID
    printf("Process ID: %d\n", getpid());

    // Close file
    close(fd);

    printf("System calls executed successfully.\n");

    return 0;
}   
