#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
    char buff[100];
    int k;

    int sock_desc;
    struct sockaddr_in client;
    sock_desc=socket(AF_INET,SOCK_STREAM,0);

    if(sock_desc==-1)
        printf("error in socket creation");
    
    client.sin_family=AF_INET;
    client.sin_port=3003;

    client.sin_addr.s_addr=INADDR_ANY;
    k=connect(sock_desc,(struct sockaddr *)&client,sizeof(client));

    if(k==-1)
        printf("error in connecting to server");

    printf("\n enter the data to be send : ");

    fgets(buff,100,stdin);
    k=send(sock_desc,buff,100,0);
    if(k==-1)
        printf("error in sending");

    close(sock_desc);
    return 0;
    
    }