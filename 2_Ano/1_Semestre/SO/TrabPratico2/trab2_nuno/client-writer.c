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
    int client_id, i, j, temp_id;
    char num_str[20];
    
    if (argc < 2) {
        client_id = getpid();
    } else {
        client_id = 0;
        i = 0;
        while (argv[1][i] >= '0' && argv[1][i] <= '9') {
            client_id = client_id * 10 + (argv[1][i] - '0');
            i++;
        }
    }
    
    server_fd = open(SERVER_FIFO, O_WRONLY);
    if (server_fd < 0) {
        exit(1);
    }
    
    strcpy(buffer, "REGISTER ");
    i = 9;
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
    while (j > 0) {
        buffer[i++] = num_str[--j];
    }
    buffer[i] = '\0';
    write(server_fd, buffer, i + 1);
    
    while (1) {
        i = 0;
        while (i < MAX_MSG_SIZE - 1) {
            msg[i] = getchar();
            if (msg[i] == EOF || msg[i] == '\n') {
                break;
            }
            i++;
        }
        msg[i] = '\0';
        
        if (i == 0 && msg[0] == EOF) {
            break;
        }
        
        if (i > 0) {
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
            i = 0;
            while (j > 0) {
                buffer[i++] = num_str[--j];
            }
            buffer[i++] = ':';
            j = 0;
            while (msg[j] != '\0' && i < MAX_MSG_SIZE - 1) {
                buffer[i++] = msg[j++];
            }
            buffer[i] = '\0';
            write(server_fd, buffer, i + 1);
        }
    }
    
    close(server_fd);
    return 0;
}
