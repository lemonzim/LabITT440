#include <stdio.h> //need for exit();
#include <stdlib.h> //for fork and getpid()
#include <unistd.h> // printf

int main(int argc, char **args){
int pid; //process id
switch(pid = fork()){
	case 0: //a fork returns 0 to the child
			printf("I am the child process: pid= %d\n", getpid());
			break;
	default: // fork return pid to the parent
			printf("I am the parent process: pid %d, child process=%d\n", getpid(),pid);
			break;
	case -1: //error
			perror("fork");
			exit(1);
}
exit(0);
}
