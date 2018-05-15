#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int fd;

void fechar(){

	close(fd);
	fd = open("/sys/class/gpio/unexport",O_WRONLY);
	write( fd, "16", 2);
	printf("Fechando o programa");
	close(fd);
	sleep(1);
	exit(0);

}

int main(){
	
	signal(SIGINT, fechar);

	printf("Começando o programa");
	fd = open( "/sys/class/gpio/export",O_WRONLY);
	write( fd, "16", 2);
	close(fd);
	sleep(1);

	fd = open("/sys/class/gpio/gpio16/direction",O_WRONLY);
	write( fd, "out", 4);
	close(fd);
	sleep(1);
	fd = open("/sys/class/gpio/gpio16/value",O_WRONLY);

	while(1){
	
	write(fd, "1", 2);
	usleep(500000);
	write(fd, "0", 2);
	usleep(500000);

	}

return 0;
}
