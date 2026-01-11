/*
 * client-writer.c
 * Cliente escritor - envio de mensagens para o servidor
 * Autor: Nuno [número]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_FIFO "/tmp/chat_server"
#define MAX_MSG_SIZE 1024

int main(int argc, char **argv) {
    int server_fd;
    char buffer[MAX_MSG_SIZE];
    char msg[MAX_MSG_SIZE];
    int client_id;
    
    if (argc < 2) {
        client_id = getpid();
    } else {
        client_id = atoi(argv[1]);
    }
    
    server_fd = open(SERVER_FIFO, O_WRONLY);
    if (server_fd < 0) {
        exit(1);
    }
    
    sprintf(buffer, "REGISTER %d", client_id);
    write(server_fd, buffer, strlen(buffer) + 1);
    
    while (1) {
        if (fgets(msg, MAX_MSG_SIZE, stdin) == NULL) {
            break;
        }
        
        msg[strcspn(msg, "\n")] = '\0';
        
        if (strlen(msg) == 0) {
            continue;
        }
        
        sprintf(buffer, "%d:%s", client_id, msg);
        write(server_fd, buffer, strlen(buffer) + 1);
    }
    
    close(server_fd);
    return 0;
}
