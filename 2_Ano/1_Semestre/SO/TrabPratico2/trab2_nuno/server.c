/*
 * server.c
 * Servidor de chat - gere registo de clientes e disseminacao de mensagens
 * Autor: Nuno [numero]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define SERVER_FIFO "/tmp/chat_server"
#define CLIENT_FIFO_PREFIX "/tmp/chat_client_"
#define MAX_MSG_SIZE 1024
#define MAX_CLIENTS 100

int clients[MAX_CLIENTS];  /* Array com IDs dos clientes registados */
int num_clients = 0;
int server_fd = -1;

/* Funcao para limpar ao terminar */
void cleanup(int sig) {
    close(server_fd);
    unlink(SERVER_FIFO);  /* Remove o FIFO do servidor */
    exit(0);
}

int main() {
    char buffer[MAX_MSG_SIZE];
    char client_fifo[256];
    int i, n, client_id, fd;

    /* Configurar handler para Ctrl+C */
    signal(SIGINT, cleanup);

    /* Remover FIFO antigo se existir e criar novo */
    unlink(SERVER_FIFO);
    if (mkfifo(SERVER_FIFO, 0666) < 0) {
        printf("Erro ao criar FIFO do servidor\n");
        return 1;
    }

    /* Abrir FIFO para leitura */
    server_fd = open(SERVER_FIFO, O_RDONLY);
    if (server_fd < 0) {
        printf("Erro ao abrir FIFO do servidor\n");
        unlink(SERVER_FIFO);
        return 1;
    }

    printf("Servidor iniciado. A aguardar clientes...\n");

    /* Ciclo principal */
    while (1) {
        n = read(server_fd, buffer, MAX_MSG_SIZE - 1);
        
        if (n <= 0) {
            /* FIFO fechado, reabrir */
            close(server_fd);
            server_fd = open(SERVER_FIFO, O_RDONLY);
            continue;
        }
        
        buffer[n] = '\0';

        /* Verificar se e registo de cliente: REGISTER <id> */
        if (strncmp(buffer, "REGISTER ", 9) == 0) {
            client_id = atoi(buffer + 9);
            if (num_clients < MAX_CLIENTS) {
                clients[num_clients] = client_id;
                num_clients++;
                printf("Cliente registado: %d\n", client_id);
            }
        }
        /* Senao e uma mensagem: <id>:<texto> */
        else {
            printf("Mensagem recebida: %s\n", buffer);

            /* Disseminar para todos os clientes registados */
            for (i = 0; i < num_clients; i++) {
                sprintf(client_fifo, "%s%d", CLIENT_FIFO_PREFIX, clients[i]);
                fd = open(client_fifo, O_WRONLY | O_NONBLOCK);
                if (fd >= 0) {
                    write(fd, buffer, strlen(buffer) + 1);
                    close(fd);
                }
            }
        }
    }

    cleanup(0);
    return 0;
}
