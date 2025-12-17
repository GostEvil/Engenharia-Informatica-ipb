// 2.9

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
 int pids[10], i, shmid_flags; char *flags;
 
 shmid_flags=shmget(IPC_PRIVATE, 10*sizeof(char), 00600);
 flags=(char*)shmat(shmid_flags, NULL, 0);
 
 for (i=0; i<10; i++)
	flags[i] = (char)-1; // mark each flag as blocked
 
 for (i=0; i<10; i++) {
	pids[i]=fork();
	if (pids[i] == 0) {
		while(flags[i] != 0); // wait for unblock
		printf("%d\n", getpid());
		flags[i] = 1; // signal printf done
		exit(0);
	}	 
 }

 for (i=0; i<10; i++) { // unblock children with even PID
	if (pids[i] % 2 == 0)
		flags[i] = (char)0;  // mark flag as unblock
 }
 
 for (i=0; i<10; i++) { // check children with even PID
	if (pids[i] % 2 == 0)
		while (flags[i] != 1);  // wait flag to be signaled
 }

 for (i=0; i<10; i++) { // unblock children with odd PID
	if (pids[i] % 2 != 0)
		flags[i] = (char)0;  // mark flag as unblock
 }
 
 for (i=0; i<10; i++) { // check children with odd PID
	if (pids[i] % 2 != 0)
		while (flags[i] != 1);  // wait flag to be signaled
 }
 
 printf("parent: done\n");
 shmctl(shmid_flags, IPC_RMID, NULL);	
 
 return(0);	
}
