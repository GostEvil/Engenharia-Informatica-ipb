//Nuno Silva, 63426
//Jorge Silva, 40230


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define SERVER_FIFO "/tmp/chat_server_fifo"
#define MAX_CLIENTS 10
#define MAX_MSG 256

typedef struct {
    pid_t pid;
    char fifo[64];
} Client;

int server_fd = -1;

void shutdown_server(int sig) {
    (void)sig;
    if (server_fd != -1)
        close(server_fd);
    unlink(SERVER_FIFO);
    printf("\n\nA encerrar servidor...\n");
    exit(0);
}

int main(void) {
    Client clients[MAX_CLIENTS];
    int num_clients = 0;
    char buffer[MAX_MSG];

    setbuf(stdout, NULL);
    signal(SIGINT, shutdown_server);

    memset(clients, 0, sizeof(clients));

    if (mkfifo(SERVER_FIFO, 0666) == -1 && errno != EEXIST) {
        printf("Erro ao criar FIFO do servidor\n");
        return 1;
    }

    printf("\n----------------------------------------\n");
    printf("\tSERVIDOR ONLINE\n");
    printf("PID: %d\n", getpid());
    printf("----------------------------------------\n");

    server_fd = open(SERVER_FIFO, O_RDWR);
    if (server_fd == -1) {
        printf("Erro ao abrir FIFO do servidor\n");
        unlink(SERVER_FIFO);
        return 1;
    }

    while (1) {
        int n = read(server_fd, buffer, MAX_MSG - 1);

        if (n > 0) {
            buffer[n] = '\0';

            int sender;
            char text[MAX_MSG];

            if (sscanf(buffer, "%d:%255[^\n]", &sender, text) == 2) {
                printf("\n>> %d | %s\n", sender, text);

                int found = 0;
                int idx = 0;
                while (idx < num_clients && !found) {
                    if (clients[idx].pid == sender) found = 1;
                    else idx++;
                }

                if (!found && num_clients < MAX_CLIENTS) {
                    clients[num_clients].pid = sender;
                    sprintf(clients[num_clients].fifo, "/tmp/chat_client_%d", sender);
                    num_clients++;
                    printf("Novo client: %d\n", sender);
                }

                int i = 0;
                while (i < num_clients) {
                    int cfd = open(clients[i].fifo, O_WRONLY);
                    if (cfd != -1) {
                        write(cfd, buffer, strlen(buffer) + 1);
                        close(cfd);
                        printf("* msg para%d\n", clients[i].pid);
                    } else {
                        printf("[!] Erro enviar msg %d\n", clients[i].pid);
                    }
                    i++;
                }
            }
        }
    }
    return 0;
}
