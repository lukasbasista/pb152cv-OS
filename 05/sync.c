#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    pid_t pid = fork();

    if ( pid < 0 )
        perror( "fork" ), exit( 2 );

    if ( pid > 0 )
    {
        int status;

        // Check if file exist in looú
        while (access("file1.txt", F_OK) != 0)
            sleep(1);
        sleep(1);

        // Open file1.txt
        int fd1 = open("file1.txt", O_RDONLY, 0666);
        if (fd1 < 0) {
            write(2, "Error:", 24);
            return 1;
        }

        // Open file2.txt
        int fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0666);
        if (fd2 < 0) {
            write(2, "Error:", 24);
            return 1;
        }

        // copy content of file1 to file2
        char buffer[1024] = {0};
        int size = read(fd1, buffer, 1024);
        write(fd2, buffer, size);

        // close files
        close(fd1);
        close(fd2);

        // Wait for child to terminate
        if ( waitpid( pid, &status, 0 ) == -1 )
            perror( "waitpid" ), exit( 2 );

        // Print result
        if ( WIFEXITED( status ) )
            printf( "%d\n",
                    WEXITSTATUS( status ) );
    }

    if ( pid == 0 )
    {
        if ( execl( "/bin/sh", "sh", "sync.sh", NULL ) == -1 )
            perror( "exec" ), exit( 2 );

    }
}
