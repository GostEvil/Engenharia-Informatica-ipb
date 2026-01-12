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
FILE *server_fp = NULL;

/* converte inteiro positivo para string */
void int_to_str(int value, char *dest) {
    char tmp[20];
    int i = 0, j;

    if (value == 0) {
        dest[0] = '0';
        dest[1] = '\0';
        return;
    }

    while (value > 0) {
        tmp[i] = (char)('0' + (value % 10));
        value = value / 10;
        i++;
    }

    for (j = 0; j < i; j++) {
        dest[j] = tmp[i - 1 - j];
    }
    dest[i] = '\0';
}

/* Funcao para limpar ao terminar */
void cleanup(int sig) {
    if (server_fp != NULL) {
        fclose(server_fp);
    }
    unlink(SERVER_FIFO);  /* Remove o FIFO do servidor */
    exit(0);
}

int main() {
    char buffer[MAX_MSG_SIZE];
    char client_fifo[256];
    char id_str[20];
    int i, client_id, len;
    FILE *client_fp;

    /* Configurar handler para Ctrl+C */
    signal(SIGINT, cleanup);

    /* Remover FIFO antigo se existir e criar novo */
    unlink(SERVER_FIFO);
    if (mkfifo(SERVER_FIFO, 0666) < 0) {
        printf("Erro ao criar FIFO do servidor\n");
        return 1;
    }

    /* Abrir FIFO para leitura */
    server_fp = fopen(SERVER_FIFO, "r");
    if (server_fp == NULL) {
        printf("Erro ao abrir FIFO do servidor\n");
        unlink(SERVER_FIFO);
        return 1;
    }

    printf("Servidor iniciado. A aguardar clientes...\n");

    /* Ciclo principal */
    while (1) {
        if (fgets(buffer, MAX_MSG_SIZE, server_fp) == NULL) {
            /* EOF no FIFO: reabrir */
            fclose(server_fp);
            server_fp = fopen(SERVER_FIFO, "r");
            if (server_fp == NULL) {
                printf("Erro ao reabrir FIFO do servidor\n");
                break;
            }
            continue;
        }

        /* remover newline lida pelo fgets */
        len = (int)strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        /* Verificar se e registo de cliente: "REGISTER <id>" */
        if (strncmp(buffer, "REGISTER ", 9) == 0) {
            client_id = atoi(buffer + 9);
            if (num_clients < MAX_CLIENTS) {
                clients[num_clients] = client_id;
                num_clients++;
                printf("Cliente registado: %d\n", client_id);
            }
        }
        /* Senao e uma mensagem: "<id>:<texto>" */
        else {
            printf("Mensagem recebida: %s\n", buffer);

            /* Disseminar para todos os clientes registados */
            for (i = 0; i < num_clients; i++) {
                int_to_str(clients[i], id_str);
                strcpy(client_fifo, CLIENT_FIFO_PREFIX);
                strcat(client_fifo, id_str);

                client_fp = fopen(client_fifo, "w");
                if (client_fp != NULL) {
                    fputs(buffer, client_fp);
                    fputc('\n', client_fp);
                    fclose(client_fp);
                }
            }
        }
    }

    cleanup(0);
    return 0;
}
