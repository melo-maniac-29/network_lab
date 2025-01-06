#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>

int main()
{
    char a[100],b[100];
    int clientsocket,port; 
    struct sockaddr_in serveraddr; 
    socklen_t len;
    struct hostent *server; 
    char message[100]; 
    
    clientsocket=socket(AF_INET,SOCK_DGRAM,0);
    
    bzero((char*)&serveraddr,sizeof(serveraddr));
    len=sizeof(serveraddr);
    serveraddr.sin_family=AF_INET;

    printf("Enter the port number ");
    scanf("%d",&port);
    serveraddr.sin_port=htons(port);
    fgets(message,2,stdin);
    printf("\nSending message for server connection\n");

    while(1){

        printf("\n enter the 1st number to be send : ");
        fgets(a,100,stdin);

        sendto(clientsocket,a,sizeof(a),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr)); 

        printf("\nenter the 2nd number to be send : ");
        fgets(b,100,stdin);

        sendto(clientsocket,b,sizeof(b),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr)); 

        printf("\nReceiving message from server.\n");
        recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,&len);
        printf("\nMessage received:\t%s\n",message);
    }

    close(clientsocket);    
}

