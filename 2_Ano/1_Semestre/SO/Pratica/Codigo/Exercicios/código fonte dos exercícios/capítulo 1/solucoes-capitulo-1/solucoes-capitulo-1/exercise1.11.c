#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// block 1 (additional headers files)
#include <stdlib.h>
#include <sys/wait.h>
		
int main() {
  int i;
  pid_t pids[10];	
  // block 2 (additional variables)
	
  // block 3 (code)	
  
  for (i=0; i<10; i++) {
    pids[i]=fork();    
  
    // block 4 (code)  
    
    if (pids[i] == 0) {
		printf("CHILD %d\n", getpid());
		exit(0);		
	}	
  }
  
  // block 5 (code)
    
  printf("PARENT: waiting for even CHILDREN\n");
  for (i=0; i<10; i++) {
	if (pids[i] % 2 == 0) {
		waitpid(pids[i], NULL, 0);
		printf("PARENT: CHILD %d died\n", pids[i]);
	}
  }
	
  printf("PARENT: waiting for odd CHILDREN\n");
  for (i=0; i<10; i++) {
	if (pids[i] % 2 != 0) {
		waitpid(pids[i], NULL, 0);
		printf("PARENT: CHILD %d died\n", pids[i]);
	}
  }
	
  return(0);
}
