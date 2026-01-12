=============================================================================
TRABALHO PRATICO 2 - APLICACAO DE CHAT COM PIPES COM NOME
Sistemas Operativos - 2024/2025
=============================================================================

AUTORES:
- Nuno [numero]
- [Nome do colega] [numero]

=============================================================================
COMPILACAO
=============================================================================

gcc -o server server.c
gcc -o client-reader client-reader.c
gcc -o client-writer client-writer.c

=============================================================================
EXECUCAO
=============================================================================

1. Iniciar o servidor (num terminal):
   ./server

2. Para cada cliente, abrir DOIS terminais:

   Terminal 1 - Cliente leitor (recebe mensagens):
   ./client-reader <id_cliente>

   Terminal 2 - Cliente escritor (envia mensagens):
   ./client-writer <id_cliente>

   IMPORTANTE: O id_cliente deve ser o MESMO nos dois terminais!

EXEMPLO com 2 clientes:
   Terminal 1: ./server
   Terminal 2: ./client-reader 1
   Terminal 3: ./client-writer 1
   Terminal 4: ./client-reader 2
   Terminal 5: ./client-writer 2

=============================================================================
FUNCIONAMENTO
=============================================================================

- O servidor cria um FIFO em /tmp/chat_server
- Cada cliente-reader cria um FIFO em /tmp/chat_client_<id>
- O client-writer regista-se no servidor e envia mensagens
- O servidor dissemina as mensagens para todos os clientes registados
- Para terminar, usar Ctrl+C

=============================================================================
NOTAS
=============================================================================

- A aplicacao usa apenas pipes com nome (FIFOs) para comunicacao
- O servidor suporta ate 100 clientes em simultaneo
- As mensagens tem tamanho maximo de 1024 bytes
