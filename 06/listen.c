#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
    int sock_fd = socket( AF_UNIX, SOCK_STREAM, 0 );
    if ( sock_fd == -1 ) {
        perror( "socket" );
        exit(1);
    }

    struct sockaddr_un sa = { .sun_family = AF_UNIX, .sun_path = "./socket" };

    unlink( "./socket" );

    if ( bind( sock_fd, ( struct sockaddr * ) &sa, sizeof( sa ) ) ) {
        perror( "bind ./socket" );
        exit(1);
    }

    if ( listen( sock_fd, 5 ) ) {
        perror( "listen" );
        exit(1);
    }

    int client_fd;
    char buffer[ 200 ];

    while ( ( client_fd = accept( sock_fd, NULL, NULL ) ) >= 0 )
    {

        if ( read( client_fd, buffer, 200 ) >= 0 ) {

            pid_t pid = fork();

            if (pid == 0){
	          	if (execl(buffer, buffer, NULL, NULL) == -1){
	          		perror(" execl ");
	          		exit(1);
	          	}
          	}

            if ( pid < 0 ) {
                perror( "fork" );
                exit(1);
            }
        }

        else {
            perror( "read" );
            exit(1);
        }

        if ( close( client_fd ) != 0 ) {
        	perror("failed closing client");
        	exit(1);
        }
    }

    return 0;
}