/*
 * client-reader.c
 * Cliente leitor - rececao e visualizacao de mensagens do servidor
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

#define CLIENT_FIFO_PREFIX "/tmp/chat_client_"
#define MAX_MSG_SIZE 1024

char client_fifo[256];

/* Funcao para limpar FIFO ao terminar */
void cleanup(int sig) {
    unlink(client_fifo);  /* Remove o FIFO do cliente */
    exit(0);
}

int main(int argc, char **argv) {
    int client_id;
    int client_fd;
    char buffer[MAX_MSG_SIZE];
    int n;

    /* Verificar se foi passado o ID do cliente */
    if (argc < 2) {
        printf("Uso: %s <id_cliente>\n", argv[0]);
        return 1;
    }

    client_id = atoi(argv[1]);

    /* Configurar handler para Ctrl+C */
    signal(SIGINT, cleanup);

    /* Criar nome do FIFO do cliente */
    sprintf(client_fifo, "%s%d", CLIENT_FIFO_PREFIX, client_id);
    
    /* Remover FIFO antigo se existir e criar novo */
    unlink(client_fifo);
    if (mkfifo(client_fifo, 0666) < 0) {
        printf("Erro ao criar FIFO do cliente\n");
        return 1;
    }

    printf("Cliente leitor iniciado. A aguardar mensagens...\n");

    /* Abrir FIFO para leitura */
    client_fd = open(client_fifo, O_RDONLY);
    if (client_fd < 0) {
        printf("Erro ao abrir FIFO do cliente\n");
        unlink(client_fifo);
        return 1;
    }

    /* Ciclo principal - ler e mostrar mensagens */
    while (1) {
        n = read(client_fd, buffer, MAX_MSG_SIZE - 1);
        if (n > 0) {
            buffer[n] = '\0';
            printf("%s\n", buffer);
        } else if (n == 0) {
            /* FIFO fechado pelo outro lado, reabrir */
            close(client_fd);
            client_fd = open(client_fifo, O_RDONLY);
            if (client_fd < 0) break;
        }
    }

    cleanup(0);
    return 0;
}
