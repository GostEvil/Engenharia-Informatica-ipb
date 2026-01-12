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

#define MAX_MSG_SIZE 1024

int main(int argc, char **argv) {
    int client_fd;
    char client_fifo[256];
    char buffer[MAX_MSG_SIZE];
    int n, i, j, client_id, temp_id;
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
        i = 0;
        while (buffer[i] != '\0') {
            putchar(buffer[i++]);
        }
        putchar('\n');
    }
    
    close(client_fd);
    remove(client_fifo);
    return 0;
}
