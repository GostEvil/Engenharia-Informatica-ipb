#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 0x00007564

int main()
{
 int option, semid;
 struct sembuf sop[1];
 
 // get the identifier of the semaphore array with key SEM_KEY
 semid=semget(SEM_KEY, 2, 0);
 sop[0].sem_flg=0;
 
 // manage room capacity
 do {
    printf("capacity of room 1: %d\n", semctl(semid, 0, GETVAL, NULL));
    printf("capacity of room 2: %d\n", semctl(semid, 1, GETVAL, NULL));
    printf("1-enter room 1\n2-enter room 2\n3-leave room 1\n4-leave room 2\n\n");
     scanf("%d", &option);
     
     switch(option){
      case 1: sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);
              printf(" --> someone entered room 1\n");
              break;
      case 2: sop[0].sem_num=1; sop[0].sem_op=-1; semop(semid, sop, 1);
              printf(" --> someone entered room 2\n");
              break;
      case 3: sop[0].sem_num=0; sop[0].sem_op=1; semop(semid, sop, 1);
              printf(" --> someone left room 1\n");
              break;
      case 4: sop[0].sem_num=1; sop[0].sem_op=1; semop(semid, sop, 1);
              printf(" --> someone left room 2\n");
              break;
     }
 } while(option>0 && option<5);

 return(0);
}
