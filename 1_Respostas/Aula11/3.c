#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/poll.h>

int fd;
int fdd;
int freq = 500000;
struct pollfd pfd;

void fechar(){

	close(fd);
	close(fdd);
	fd = open("/sys/class/gpio/unexport",O_WRONLY);
	write( fd, "16", 2);
	close(fd);
	system("echo 21 > /sys/class/gpio/unexport");
	printf("Fechando o programa");
	close(pfd.fd);
	sleep(1);
	exit(0);

}

void dobraFrequencia(){

	freq = freq/2;

}

int main(){

	signal(SIGINT, fechar);

	pid_t child_pid;
	
	child_pid = fork();

	if(child_pid == 0){

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
	usleep(freq);
	write(fd, "0", 2);
	usleep(freq);

		}
	}else{
	
	char botao;

/*
	fdd = open(fdd, "/sys/class/gpio/export", O_WRONLY);
	write(fdd,"21",2);
	close(fdd);

	fdd = open(fdd,"/sys/class/gpio/gpio21/direction",O_WRONLY);
	write(fdd,"in",4);
	close(fdd);

	fdd = open(fdd,"/sys/class/gpio/gpio21/value",O_RDWR);
*/

	system("echo 21 > /sys/class/gpio/export");
	system("echo falling > sys/class/gpio/gpio21/edge");
	system("echo in> sys/class/gpio/gpio21/direction");
	pfd.fd = open("/sys/class/gpio/gpio21/value",O_RDONLY);

	while(1){
	
	//	lseek(fdd,0,SEEK_SET);
		read(pfd.fd,&botao,1);	
	/*
		if(botao == '1'){
			dobrarFrequencia;
			usleep(300000);
			}
	*/
	pfd.events = POLLPRI | POLLERR;
	pfd.revents = 0;
	poll(&pfd,1,-1);	
	dobraFrequencia;
	usleep(300000);

		}

	}


return 0;
}
