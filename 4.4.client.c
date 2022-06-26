#include<stdio.h>
#include<sys/socket.h>
#include<string.h> // to use strlen
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include<stdlib.h>
int main(int argc , char *argv[])
{
	int socket_desc, n=0;
	struct sockaddr_in server; 
	char message[2000];
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
		
	server.sin_addr.s_addr = inet_addr("192.168.56.105");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888);

	//Connect to remote server
	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}
	
	puts("Connected \n");


	while(1)
	{
		bzero(message,sizeof(message));
		printf("Client:");
		//Get client input
		 while ((message[n++] = getchar()) != '\n') 
            ; 
		//Send some data
		write(socket_desc, message, sizeof(message));
		bzero(message,sizeof(message));
		read(socket_desc, message, sizeof(message));
		printf("Server: %s", message);
		if(strcmp(message, ":exit") == 0){
			printf("Disconnected\n");
			exit(1);
		}
	}
	
	close(socket_desc);
	return 0;
}


