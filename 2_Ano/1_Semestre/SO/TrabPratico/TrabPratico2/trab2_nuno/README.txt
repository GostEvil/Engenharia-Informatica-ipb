Trabalho Prático 2 – Sistemas Operativos
Sistema de Chat com FIFOs (Named Pipes)

Trabalho realizado por:
Nuno Silva, 63426
Jorge Silva, 40230

Ficheiros: server.c, client-reader.c, client-writer.c e README.txt

- Compilação
gcc -o s server.c
gcc -o cr client-reader.c
gcc -o cw client-writer.c

- Execução
Abrir 3 CMDs
[CMD1] - Server
./s

[CMD2] - Reader
./cr

Copiar o PID para colocar na CMD3

[CMD3] -  Writer
./cw 'PID'

