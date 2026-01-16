#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x00007564
#define SEM_KEY 0x00007564

int main()
{
 int semid, shmid, *shmaddr, i;
 struct sembuf sop[1];
 
 // get the identifier of the shared memory zone with key SHM_KEY
 shmid=shmget(SHM_KEY, sizeof(int), 0);
 
 // attach a virtual address (chosen by the OS) to the zone
 shmaddr=(int*)shmat(shmid, NULL, 0);
 
 // get the identifier of the semaphore array with key SEM_KEY
 semid=semget(SEM_KEY, 1, 0);
 
 // concurrent access to the shared memory zone
 for(i=1;i<=1000000;i++){
 
     // entry section (down)
     sop[0].sem_num=0; sop[0].sem_op=-1; sop[0].sem_flg=0; semop(semid, sop, 1);
     
     // critical zone
     (*shmaddr)++;
     
     // exit section (down)
     sop[0].sem_num=0; sop[0].sem_op=1; sop[0].sem_flg=0; semop(semid, sop, 1);
 }
 
 printf("*shmaddr = %d\n", *shmaddr);
 
 // note: shared memory and semaphore array not removed; use ipcs and ipcrm

 return(0);
}
