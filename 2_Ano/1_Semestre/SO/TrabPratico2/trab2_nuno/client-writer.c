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
    long client_id = (argc > 1) ? strtol(argv[1], NULL, 10) : (long)getpid();
    int server_fd;
    char buffer[MAX_MSG_SIZE];
    char msg[MAX_MSG_SIZE];

    server_fd = open(SERVER_FIFO, O_WRONLY);
    if (server_fd < 0) {
        fprintf(stderr, "erro ao abrir fifo do servidor\n");
        return 1;
    }

    int n = snprintf(buffer, sizeof(buffer), "REGISTER %ld", client_id);
    if (n < 0 || n >= (int)sizeof(buffer) || write(server_fd, buffer, n + 1) < 0) {
        fprintf(stderr, "erro ao registar cliente\n");
        close(server_fd);
        return 1;
    }

    while (fgets(msg, sizeof(msg), stdin)) {
        size_t len = strlen(msg);
        if (len && msg[len - 1] == '\n') msg[len - 1] = '\0';
        if (msg[0] == '\0') continue;
        n = snprintf(buffer, sizeof(buffer), "%ld:%s", client_id, msg);
        if (n < 0 || n >= (int)sizeof(buffer)) continue;
        if (write(server_fd, buffer, n + 1) < 0) {
            fprintf(stderr, "erro ao enviar mensagem\n");
            break;
        }
    }

    close(server_fd);
    return 0;
}
