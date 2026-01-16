#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 0x00007564

int main()
{
  int semid; union semun { int val; } arg; 
  // alternative: union semun {ushort array[2]; } arg;

  // create a non-private semaphore array with two semaphores
  semid=semget(SEM_KEY, 2, 00600|IPC_CREAT|IPC_EXCL);

  // initialize the semaphores counters with the room capacities
  arg.val=5; semctl(semid, 0, SETVAL, arg);
  arg.val=10; semctl(semid, 1, SETVAL, arg);
  // alternative: arg.array[0]=5; arg.array[1]=10; semctl(semid, 0, SETALL, arg);

  return(0);
}
