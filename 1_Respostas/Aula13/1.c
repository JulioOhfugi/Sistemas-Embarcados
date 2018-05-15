#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define TTY "/dev/ttyS0"
int uart0_fd;

void ctrl_c(){
    puts("Fechando" TTY);
    close(uart0_fd);
    exit (-1);
}

float f_media(char input){
    float media=0;

    for(int i=0; i<100; i++){
        media = media + input[i];
    }

    media = media/100;

    return media;

}


int main ()
{

    struct termios options;
    char input[100];
    float media;

    signal(SIGINT, ctrl_c);
    uart0_fd = open(TTY, O_RDWR);
    if(uart0_fd == 1){
        puts("Erro abrido a UART");
        return -1;
    }
    puts(TTY"aberto");
    tcgetattr(uart0_fd, &options);
    options.c_cflag = CS8 | CREAD | CLOCAL;
    options.c_iflag = 0;
    options.c_lflag = 0;
    options.c_cc[VTIME] = 0;
    options.c_cc[VMIN] = 1;
    cfsetospeed(&options, B9600);
    cfsetispeed(&options, B9600);
    tcflush(uart0_fd, TCIOFLUSH);
    tcsetattr(uart0_fd, TCSANOW, &options);
    puts("UART configurada");
    system( "stty -f"TTY);  //mostrar as configuracoes da UART

    while(1){

        for(int i=0; i<100; i++){
            if(read(uart0_fd, &input,sizeof(char))>0){
                lseek(uart0_fd,0, SEEK_SET);
            }else{
                printf("erro na leitura");
            }
        }
        media = f_media(input);
        printf("Media = %.2f", media);
        sleep(1);
    }


	return 0;
}












