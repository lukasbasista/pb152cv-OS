#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

const uint32_t REMOTE_IP = 0x7F000001;
const uint16_t REMOTE_PORT = 2136;

int main()
{
	int sock_fd = socket( AF_INET, SOCK_STREAM, 0 );

	if ( sock_fd == -1 )
		return perror( "socket" ), 2;

	struct sockaddr_in sa = { .sin_family = AF_INET,
						      .sin_addr = { htonl( REMOTE_IP ) },
						      .sin_port = htons( REMOTE_PORT ) };

	if ( connect( sock_fd, ( struct sockaddr * ) &sa,
                  sizeof( sa ) ) == -1 )
        return perror( "connect to 147.251.48.1:80" ), 2;

	char buf[29] = "you said ";
	int bytes = read( sock_fd , buf + 9, 20);
   	
	write( sock_fd, buf, bytes + 9 );

	close( sock_fd );
	return 0;
						    
}