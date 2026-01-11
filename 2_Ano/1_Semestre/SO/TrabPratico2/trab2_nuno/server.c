/*
 * server.c
 * Servidor de chat - gestão de sala de chat
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
#define CLIENT_FIFO_TEMPLATE "/tmp/chat_client_%d"
#define MAX_CLIENTS 100
#define MAX_MSG_SIZE 1024

typedef struct {
    int client_id;
    int fd;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

int find_client(int client_id) {
    int i;
    for (i = 0; i < num_clients; i++) {
        if (clients[i].client_id == client_id) {
            return i;
        }
    }
    return -1;
}

int add_client(int client_id) {
    char client_fifo[256];
    int fd;
    
    if (num_clients >= MAX_CLIENTS) {
        return -1;
    }
    
    if (find_client(client_id) != -1) {
        return 0;
    }
    
    sprintf(client_fifo, CLIENT_FIFO_TEMPLATE, client_id);
    fd = open(client_fifo, O_WRONLY);
    if (fd < 0) {
        return -1;
    }
    
    clients[num_clients].client_id = client_id;
    clients[num_clients].fd = fd;
    num_clients++;
    
    return 0;
}

void broadcast_message(char *msg, int sender_id) {
    int i;
    char full_msg[MAX_MSG_SIZE + 64];
    
    sprintf(full_msg, "[Cliente %d]: %s", sender_id, msg);
    
    for (i = 0; i < num_clients; i++) {
        if (clients[i].client_id != sender_id) {
            write(clients[i].fd, full_msg, strlen(full_msg) + 1);
        }
    }
}

int main() {
    int server_fd;
    char buffer[MAX_MSG_SIZE];
    int client_id;
    char client_fifo[256];
    int n;
    
    mkfifo(SERVER_FIFO, 00666);
    chmod(SERVER_FIFO, 00666);
    
    server_fd = open(SERVER_FIFO, O_RDONLY);
    if (server_fd < 0) {
        exit(1);
    }
    
    while (1) {
        n = read(server_fd, buffer, MAX_MSG_SIZE);
        if (n <= 0) {
            continue;
        }
        
        buffer[n] = '\0';
        
        if (sscanf(buffer, "REGISTER %d", &client_id) == 1) {
            sprintf(client_fifo, CLIENT_FIFO_TEMPLATE, client_id);
            mkfifo(client_fifo, 00666);
            chmod(client_fifo, 00666);
            add_client(client_id);
        } else {
            sscanf(buffer, "%d:%[^\n]", &client_id, buffer);
            broadcast_message(buffer, client_id);
        }
    }
    
    close(server_fd);
    remove(SERVER_FIFO);
    return 0;
}
