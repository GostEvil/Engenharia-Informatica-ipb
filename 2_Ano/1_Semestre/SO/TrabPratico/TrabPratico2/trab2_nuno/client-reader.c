
//enviei o cr diferente por engano, mas acho q este tmb da :D
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define SERVER_FIFO "/tmp/chat_server_fifo"
#define MAX_MSG 256

char my_fifo[64];

void stop_handler(int sig) {
    (void)sig;
    unlink(my_fifo);
    printf("\n\nA encerrar reader...\n");    
    exit(0);
}

int main(void) {
    char buffer[MAX_MSG];
    pid_t pid = getpid();

    setbuf(stdout, NULL);
    signal(SIGINT, stop_handler);

    sprintf(my_fifo, "/tmp/chat_client_%d", pid);

    if (mkfifo(my_fifo, 0666) == -1 && errno != EEXIST) {
        printf("Erro ao criar FIFO do client\n");
        return 1;
    }

    printf("\n----------------------------------------\n");
    printf("\tCLIENT READER\n");
    printf("\tPID: %d\n", pid);
    printf("----------------------------------------\n");

    int sfd = open(SERVER_FIFO, O_WRONLY);
    if (sfd != -1) {
        char login[MAX_MSG];
        sprintf(login, "%d:[+] User", pid);
        write(sfd, login, strlen(login) + 1);
        close(sfd);
    } else {
        printf("Servidor offline\n");
    }

    int fd = open(my_fifo, O_RDWR);
    if (fd == -1) {
        printf("Erro ao abrir FIFO do cliente\n");
        unlink(my_fifo);
        return 1;
    }

    while (1) {
        int n = read(fd, buffer, MAX_MSG - 1);
        if (n > 0) {
            buffer[n] = '\0';
            int sender;
            char msg[MAX_MSG];

            if (sscanf(buffer, "%d:%255[^\n]", &sender, msg) == 2) { printf("[%d]: %s\n", sender, msg);}
        }
    }