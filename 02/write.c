#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		write(2, "Error:(\nasd)", 24);
		return 1;
	}
	int fd = open(argv[1], O_RDWR | O_CREAT, 0666);
	if (fd < 0) {
		write(2, "Error:", 24);
		return 1;
	}
	char buffer[1024] = {0};
	int size = read(STDIN_FILENO, buffer, 1024);
	write(fd, buffer, size);
	close(fd);
	return 0;	
}