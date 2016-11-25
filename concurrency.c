#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



/* Basic funcionality of fork. 
	INPUT: None
	OUTPUT: Print statments
*/
void one(){
	pid_t pid, x, pid2;
	pid = fork();

	//Enter if a child process
	if(pid == 0){
		printf("We are in the child process, with pid = %d\n", pid);
	}

	pid2 = fork();
	printf("This line should print four times\n");
}

void two (int N){
	int status, i;
	pid_t pid;

	//Parent creates N children
	for (i = 0; i < N; i++)
		//Forks the children. The parent does not enter the if: only children
		//Children terminate as soon as they fork
		//If child terminates before parent is at line 39, the waitpid exits immediately
		if ((pid = fork()) == 0)  
			exit(100 + i);

	//The parent waits on all of its children. As each child finishes, pid is returned and printed
	while ((pid = waitpid(-1,&status,0)) > 0)
		if(WIFEXITED(status))
			printf("child %d terminated normally with exit status = %d\n", pid, WEXITSTATUS(status));

		else
			printf("child %d terminated abnormally \n", pid);

	/*
	if (errno != ECHILD)
		unix_error("waitpid error");
	*/
}

int main(){

	//one();
	two(5);

	exit(1);	
}