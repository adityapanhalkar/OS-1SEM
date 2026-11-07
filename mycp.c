#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int src, dest, n;
    char buffer[1024];

    // Open source file
    src = open("source.txt", O_RDONLY);

    if (src < 0)
    {
        perror("Source file opening failed");
        return 1;
    }

    // Create destination file
    dest = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest < 0)
    {
        perror("Destination file opening failed");
        close(src);
        return 1;
    }

    // Read and write data
    while ((n = read(src, buffer, sizeof(buffer))) > 0)
    {
        if (write(dest, buffer, n) != n)
        {
            perror("File writing failed");
            close(src);
            close(dest);
            return 1;
        }
    }

    if (n < 0)
    {
        perror("File reading failed");
        close(src);
        close(dest);
        return 1;
    }

    // Close both files
    close(src);
    close(dest);

    printf("File copied successfully!\n");

    return 0;
}
