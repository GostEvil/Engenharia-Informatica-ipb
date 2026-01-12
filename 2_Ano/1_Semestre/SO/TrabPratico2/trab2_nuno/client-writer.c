/*
 * client-writer.c
 * Cliente escritor - envio de mensagens para o servidor
 * Autor: Nuno [numero]
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

int main(int argc, char **argv) {
    int client_id;
    FILE *server_fp;
    char buffer[MAX_MSG_SIZE];
    char msg[MAX_MSG_SIZE];
    char id_str[20];
    int n;

    /* Verificar se foi passado o ID do cliente como argumento */
    if (argc < 2) {
        printf("Uso: %s <id_cliente>\n", argv[0]);
        return 1;
    }

    client_id = atoi(argv[1]);
    int_to_str(client_id, id_str);

    /* Abrir FIFO do servidor para escrita */
    server_fp = fopen(SERVER_FIFO, "w");
    if (server_fp == NULL) {
        printf("Erro ao abrir FIFO do servidor\n");
        return 1;
    }

    /* Registar cliente no servidor: "REGISTER <id>" */
    strcpy(buffer, "REGISTER ");
    strcat(buffer, id_str);
    fputs(buffer, server_fp);
    fputc('\n', server_fp);
    fflush(server_fp);

    printf("Cliente escritor iniciado. Escreva mensagens:\n");

    /* Ler mensagens do teclado e enviar ao servidor */
    while (fgets(msg, sizeof(msg), stdin) != NULL) {
        /* Remover newline */
        n = (int)strlen(msg);
        if (n > 0 && msg[n - 1] == '\n') {
            msg[n - 1] = '\0';
        }

        /* Ignorar linhas vazias */
        if (msg[0] == '\0') continue;

        /* Formatar mensagem: "<id>:<texto>" */
        strcpy(buffer, id_str);
        strcat(buffer, ":");
        strcat(buffer, msg);

        fputs(buffer, server_fp);
        fputc('\n', server_fp);
        fflush(server_fp);
    }

    fclose(server_fp);
    return 0;
}
