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
    int fd, temp_id, i, j;
    char num_str[20];
    
    if (num_clients >= MAX_CLIENTS) {
        return -1;
    }
    
    if (find_client(client_id) != -1) {
        return 0;
    }
    
    strcpy(client_fifo, "/tmp/chat_client_");
    temp_id = client_id;
    i = 0;
    if (temp_id == 0) {
        num_str[i++] = '0';
    } else {
        while (temp_id > 0) {
            num_str[i++] = '0' + (temp_id % 10);
            temp_id = temp_id / 10;
        }
    }
    j = 17;
    while (i > 0) {
        client_fifo[j++] = num_str[--i];
    }
    client_fifo[j] = '\0';
    
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
    int i, j, len, temp_id;
    char full_msg[MAX_MSG_SIZE + 64];
    char num_str[20];
    
    len = 0;
    full_msg[len++] = '[';
    full_msg[len++] = 'C';
    full_msg[len++] = 'l';
    full_msg[len++] = 'i';
    full_msg[len++] = 'e';
    full_msg[len++] = 'n';
    full_msg[len++] = 't';
    full_msg[len++] = 'e';
    full_msg[len++] = ' ';
    
    temp_id = sender_id;
    i = 0;
    if (temp_id == 0) {
        num_str[i++] = '0';
    } else {
        while (temp_id > 0) {
            num_str[i++] = '0' + (temp_id % 10);
            temp_id = temp_id / 10;
        }
    }
    while (i > 0) {
        full_msg[len++] = num_str[--i];
    }
    
    full_msg[len++] = ']';
    full_msg[len++] = ':';
    full_msg[len++] = ' ';
    
    i = 0;
    while (msg[i] != '\0' && len < MAX_MSG_SIZE + 60) {
        full_msg[len++] = msg[i++];
    }
    full_msg[len] = '\0';
    
    for (i = 0; i < num_clients; i++) {
        if (clients[i].client_id != sender_id) {
            write(clients[i].fd, full_msg, len + 1);
        }
    }
}

int main() {
    int server_fd;
    char buffer[MAX_MSG_SIZE];
    int client_id, msg_type;
    char client_fifo[256];
    int n, i, j, temp_id;
    char num_str[20];
    
    mkfifo(SERVER_FIFO, 00600);
    chmod(SERVER_FIFO, 00600);
    
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
        
        if (buffer[0] == 'R' && buffer[1] == 'E' && buffer[2] == 'G') {
            i = 9;
            client_id = 0;
            while (buffer[i] >= '0' && buffer[i] <= '9') {
                client_id = client_id * 10 + (buffer[i] - '0');
                i++;
            }
            
            strcpy(client_fifo, "/tmp/chat_client_");
            temp_id = client_id;
            j = 0;
            if (temp_id == 0) {
                num_str[j++] = '0';
            } else {
                while (temp_id > 0) {
                    num_str[j++] = '0' + (temp_id % 10);
                    temp_id = temp_id / 10;
                }
            }
            i = 17;
            while (j > 0) {
                client_fifo[i++] = num_str[--j];
            }
            client_fifo[i] = '\0';
            
            mkfifo(client_fifo, 00600);
            chmod(client_fifo, 00600);
            add_client(client_id);
        } else {
            i = 0;
            client_id = 0;
            while (buffer[i] >= '0' && buffer[i] <= '9') {
                client_id = client_id * 10 + (buffer[i] - '0');
                i++;
            }
            if (buffer[i] == ':') {
                i++;
                j = 0;
                while (buffer[i] != '\0' && j < MAX_MSG_SIZE - 1) {
                    buffer[j++] = buffer[i++];
                }
                buffer[j] = '\0';
                broadcast_message(buffer, client_id);
            }
        }
    }
    
    close(server_fd);
    remove(SERVER_FIFO);
    return 0;
}
