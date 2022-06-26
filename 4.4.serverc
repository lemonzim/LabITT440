#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write
#include<stdlib.h>
#include <sys/types.h>
int main(int argc , char *argv[])
{
	int socket_desc , new_socket , c,n = 0;
	struct sockaddr_in server , client;
	char message[2000];
	pid_t childpid;
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons( 8888 );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("bind failed");
		return 1;
	}
	puts("bind done");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	
	if((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))<0){exit(1);}
	printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
		
		
			
	while(1)
	{
			bzero(message,sizeof(message));
			//read message and copy to message
			read(new_socket, message, sizeof(message));
			if(strcmp(message, ":exit") == 0){
			printf("Disconnected from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
			break;
			}else{
				//print message
				printf("Client: %s", message);
				bzero(message, sizeof(message));
				
				//Server get input and copy to message
				printf("Server:");
				while ((message[n++] = getchar()) != '\n') ; 
				//send messaage to client
				write(new_socket, message, sizeof(message));
					}//else
	}//while
	return 0;
	close(new_socket);
}
