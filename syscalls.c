#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[20];

    // Open or create a file
    fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if (fd < 0)
    {
        perror("File opening failed");
        return 1;
    }

    // Write data into the file
    write(fd, "Hello Linux", 11);

    // Move file pointer to the beginning
    lseek(fd, 0, SEEK_SET);

    // Read data from the file
    read(fd, buffer, 11);
    buffer[11] = '\0';

    printf("File Content: %s\n", buffer);

    // Display process ID
    printf("Process ID: %d\n", getpid());

    // Display user ID
    printf("User ID: %d\n", getuid());

    // Display group ID
    printf("Group ID: %d\n", getgid());

    // Close the file
    close(fd);

    return 0;
}
