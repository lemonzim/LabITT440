#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int checkPrime(int number)
{
  int count = 0;
  for(int i=2; i<=number/2; i++)
  {
     if(number%i == 0)
     {
       count=1;
       break;
     }
  }
  if(number == 1) {count = 1;}
  return count;
}
void sigint_handler(int sig)
{
  printf("This is a special signal handler for SIGINT\n");
}
int main(void) {
void sigint_handler(int sig);

  if (signal(SIGINT, sigint_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  int pass[2];
  pipe(pass);
  pid_t pid = fork();
 
  if(pid > 0) {
    close(0);
    close(pass[1]);
    dup(pass[0]);
 
    int numb_prime;
    printf("Waiting for Number...\n");
    wait(NULL);
	read(pass[0], &numb_prime, sizeof(numb_prime));
    if(checkPrime(numb_prime) ==0)
	{printf("%d is a prime number.", numb_prime);}
	else
	{printf("%d is not a prime number.", numb_prime);}
  }
  else if(pid == 0) {
    close(pass[0]);
    dup(pass[1]);
 
	int numb;
	printf("This is a child process. Please enter a number. > ");
	scanf("%d", &numb);
	printf("\nThank you, the parent will determine whether the number is a prime or not\n");
    write(pass[1], &numb, sizeof(numb));
    exit(EXIT_SUCCESS);
  }
 
  return EXIT_SUCCESS;
}
