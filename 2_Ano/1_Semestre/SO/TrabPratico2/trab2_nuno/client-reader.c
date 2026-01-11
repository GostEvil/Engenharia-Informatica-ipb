/*
 * client-reader.c
 * Cliente leitor - receção e visualização de mensagens do servidor
 * Autor: Nuno [número]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CLIENT_FIFO_TEMPLATE "/tmp/chat_client_%d"
#define MAX_MSG_SIZE 1024

int main(int argc, char **argv) {
    int client_fd;
    char client_fifo[256];
    char buffer[MAX_MSG_SIZE];
    int client_id;
    int n;
    
    if (argc < 2) {
        client_id = getpid();
    } else {
        client_id = atoi(argv[1]);
    }
    
    sprintf(client_fifo, CLIENT_FIFO_TEMPLATE, client_id);
    mkfifo(client_fifo, 00666);
    chmod(client_fifo, 00666);
    
    client_fd = open(client_fifo, O_RDONLY);
    if (client_fd < 0) {
        exit(1);
    }
    
    while (1) {
        n = read(client_fd, buffer, MAX_MSG_SIZE);
        if (n <= 0) {
            break;
        }
        
        buffer[n] = '\0';
        printf("%s\n", buffer);
        fflush(stdout);
    }
    
    close(client_fd);
    remove(client_fifo);
    return 0;
}
