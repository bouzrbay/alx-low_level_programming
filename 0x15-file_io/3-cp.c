#include "main.h"

/**
 *error_file - ...
 *
 *@file_from: ...
 *@file_to: ...
 *@argv: ...
 *
 */

#define BUFFER_SIZE 1024

void error_file(int fd_from, int fd_to, char *argv[])
{

if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}

/**
 * main - ...
 *
 * @argc: number of arguments.
 * @argv: arguments vector.
 * 
 *Return: ...
 */
int main(int argc, char *argv[])
{

char buffer[1024];
int fd_from = open(argv[1], O_RDONLY);
int fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
int errorclose;
ssize_t bytes_read, bytes_written;
error_file(fd_from, fd_to, argv);

if (argc != 3)
{
dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
exit(97);
}

bytes_read = 1024;
do {
bytes_read = read(fd_from, buffer, BUFFER_SIZE);
if (bytes_read == -1)
error_file(-1, 0, argv);

bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
error_file(0, -1, argv);

} while (bytes_read == 1024);

errorclose = close(fd_from);
if (errorclose == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}
errorclose = close(fd_to);
if (errorclose == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

return (0);
}
