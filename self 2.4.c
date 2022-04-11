#include <stdio.h> //need for exit();
#include <stdlib.h> //for fork and getpid()
#include <unistd.h> // printf
#include <sys/wait.h> // wait
#include <sys/types.h>
void childTask(){
int age;
printf("Hi, how old are you? > ");
scanf("%d", &age);
printf("You are %d years old\n", age);
}
int main(void){
for(int i =1 ; i<5 ;i++){
pid_t pid = fork();
 if (pid ==0){
	 childTask();
	 exit(0);
}
else if(pid > 0 ){
	printf("Saya adalah bapaknya\n");
	printf("Waiting for child process to finish....\n");
	wait(NULL);
	printf("JOB is done\n");
}
else{
	printf("Unable to create a child process\n");
}
}
return EXIT_SUCCESS;
}
