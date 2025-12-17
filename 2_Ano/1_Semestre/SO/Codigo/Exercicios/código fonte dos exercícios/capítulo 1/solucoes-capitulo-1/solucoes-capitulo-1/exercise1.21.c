#include <stdio.h>
// block 1 (additional headers files)
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{	
	char Operations[8][2]={"+",".","+",".","-",".","-","."};
	int A[8]={1,2,3,4,5,6,7,8}, B[8]={8,7,6,5,4,3,2,1}, i;
	// block 2 (more variables)	
	int status, result;
	
	for (i=0; i<8; i++) {
				
		// block 3 (code)
		
		if (fork()==0) {			
			char num1[10],num2[10];
			
			sprintf(num1,"%d",A[i]); sprintf(num2,"%d",B[i]);
			
			execl("./mycalc.exe", "mycalc.exe", Operations[i], num1, num2, NULL);
			
			exit(0);
		}				
	}

	// block 4 (code)
	
	result=0;
	while(wait(&status)!=-1)
			result += WEXITSTATUS(status);			
			
	printf("result: %d\n", result);	
	//84 = (1+8)+(2*7)+(3+6)+(4*5)+(5-4)+(6*3)+(7-2)+(8*1)
}
