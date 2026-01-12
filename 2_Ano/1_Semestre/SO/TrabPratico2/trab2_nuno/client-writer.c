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

int main(int argc, char **argv) {
    int client_id;
    int server_fd;
    char buffer[MAX_MSG_SIZE];
    char msg[MAX_MSG_SIZE];
    int n;

    /* Verificar se foi passado o ID do cliente como argumento */
    if (argc < 2) {
        printf("Uso: %s <id_cliente>\n", argv[0]);
        return 1;
    }

    client_id = atoi(argv[1]);

    /* Abrir FIFO do servidor para escrita */
    server_fd = open(SERVER_FIFO, O_WRONLY);
    if (server_fd < 0) {
        printf("Erro ao abrir FIFO do servidor\n");
        return 1;
    }

    /* Registar cliente no servidor */
    n = sprintf(buffer, "REGISTER %d", client_id);
    write(server_fd, buffer, n + 1);

    printf("Cliente escritor iniciado. Escreva mensagens:\n");

    /* Ler mensagens do teclado e enviar ao servidor */
    while (fgets(msg, sizeof(msg), stdin) != NULL) {
        /* Remover newline */
        n = strlen(msg);
        if (n > 0 && msg[n - 1] == '\n') {
            msg[n - 1] = '\0';
        }
        
        /* Ignorar linhas vazias */
        if (msg[0] == '\0') continue;

        /* Formatar e enviar mensagem */
        n = sprintf(buffer, "%d:%s", client_id, msg);
        write(server_fd, buffer, n + 1);
    }

    close(server_fd);
    return 0;
}
