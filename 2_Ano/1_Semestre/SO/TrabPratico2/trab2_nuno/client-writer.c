/*
    client-writer.c
    Trabalho Prático 2 - Sistemas Operativos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define SERVER_FIFO "/tmp/chat_server_fifo"
#define MAX_MSG 256

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./client-writer <PID_DO_LEITOR>\n");
        return 1;
    }

    int pid = atoi(argv[1]);
    if (pid <= 0) {
        printf("PID invalido\n");
        return 1;
    }

    int fd = open(SERVER_FIFO, O_WRONLY);
    if (fd == -1) {
        printf("Servidor offline\n");
        return 1;
    }

    printf("----------------------------------------\n");
    printf("\tCLIENT WRITER\n");
    printf("\tPID: %d\n", pid);
    printf("----------------------------------------\n");
    printf("Escrever 'sair' para terminar\n\n");

    while (1) {
        char msg[MAX_MSG];
        char buffer[MAX_MSG];

        printf("> ");
        fgets(msg, MAX_MSG, stdin);
        msg[strcspn(msg, "\n")] = '\0';

        if (strcmp(msg, "sair") == 0) break;

        sprintf(buffer, "%d:%s", pid, msg);
        write(fd, buffer, strlen(buffer) + 1);
    }

    close(fd);
    return 0;
}