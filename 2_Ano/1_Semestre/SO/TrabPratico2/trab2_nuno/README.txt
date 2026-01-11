Trabalho Prático 2 - Aplicação de Chat
Sistemas Operativos - 2025/2026

Autores: Nuno [número]

================================================================================
COMPILAÇÃO
================================================================================

Para compilar os três programas, utilize os seguintes comandos:

gcc -o server server.c
gcc -o client-writer client-writer.c
gcc -o client-reader client-reader.c

Ou, alternativamente, pode compilar todos de uma vez:

gcc -o server server.c && gcc -o client-writer client-writer.c && gcc -o client-reader client-reader.c

================================================================================
EXECUÇÃO
================================================================================

A aplicação requer a execução de múltiplos terminais:

1. TERMINAL 1 - Servidor:
   ./server

2. TERMINAIS 2 e 3 - Cliente 1 (escritor e leitor):
   Terminal 2: ./client-reader 1
   Terminal 3: ./client-writer 1

3. TERMINAIS 4 e 5 - Cliente 2 (escritor e leitor):
   Terminal 4: ./client-reader 2
   Terminal 5: ./client-writer 2

E assim sucessivamente para cada cliente adicional (usando IDs diferentes).

NOTA: É importante iniciar primeiro o servidor, depois os clientes.
   O client-reader deve ser iniciado ANTES do client-writer correspondente
   para que o FIFO do cliente esteja criado quando o escritor se registar.
   Ambos os processos (reader e writer) devem usar o MESMO ID de cliente.
   
   Se não for fornecido um ID como argumento, cada processo usará o seu
   próprio PID, o que não permitirá a coordenação entre reader e writer.

================================================================================
FUNCIONAMENTO
================================================================================

- O servidor cria um FIFO bem conhecido (/tmp/chat_server) para receber
  mensagens dos clientes.

- Cada cliente escritor envia uma mensagem de registo ao servidor com o seu PID.

- O servidor cria um FIFO específico para cada cliente (/tmp/chat_client_PID).

- Quando um cliente escritor envia uma mensagem, o servidor recebe-a e
  dissemina-a por todos os clientes registados (exceto o remetente).

- Cada cliente leitor recebe e exibe as mensagens no seu terminal.

- Para terminar um cliente escritor, utilize Ctrl+D (EOF).

- Para terminar o servidor, utilize Ctrl+C.

================================================================================
NOTAS
================================================================================

- Os FIFOs são criados no diretório /tmp.

- Se os FIFOs já existirem de uma execução anterior, pode ser necessário
  removê-los manualmente antes de iniciar uma nova execução:
  rm /tmp/chat_server /tmp/chat_client_*

- A aplicação suporta até 100 clientes simultâneos.

- As mensagens têm um tamanho máximo de 1024 caracteres.

================================================================================
