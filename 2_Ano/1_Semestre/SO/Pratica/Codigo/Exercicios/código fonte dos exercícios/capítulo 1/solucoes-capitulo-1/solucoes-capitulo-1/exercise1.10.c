#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// block 1 (additional headers files)
#include <stdlib.h>
#include <sys/wait.h>
		
int main() {
  int i, num_pids_even=0, num_pids_odd=0;
  pid_t pid, pids_even[10], pids_odd[10];	
  // block 2 (additional variables)
	
  // block 3 (code)	
  
  for (i=0; i<10; i++) {
    pid=fork();    
  
    // block 4 (code)  
    
    if (pid == 0) {
		printf("CHILD %d\n", getpid());
		exit(0);		
	}
	else if (pid % 2 == 0) {
		pids_even[num_pids_even] = pid;
		num_pids_even ++;     
	}
	else {
		pids_odd[num_pids_odd] = pid;
		num_pids_odd ++;     
	}	
  }
  
  // block 5 (code)
    
  printf("PARENT: waiting for even CHILDREN\n");
  for (i=0; i<num_pids_even; i++) {
	pid=waitpid(pids_even[i], NULL, 0);
	printf("PARENT: CHILD %d died\n", pid);
  }
	
  printf("PARENT: waiting for odd CHILDREN\n");
  for (i=0; i<num_pids_odd; i++) {
	pid=waitpid(pids_odd[i], NULL, 0);
	printf("PARENT: CHILD %d died\n", pid);
  }
	
  return(0);
}
