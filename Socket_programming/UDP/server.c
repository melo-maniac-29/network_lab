#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>

int main()
{
    int serversocket,port;  
    struct sockaddr_in serveraddr,clientaddr; 
    socklen_t len; 
    char a[100],b[100],k[100];
    serversocket=socket(AF_INET,SOCK_DGRAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr)); 
    printf("Enter the port number ");
    scanf("%d",&port);

    
    serveraddr.sin_port=htons(port);
    
   
    bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

    printf("\nWaiting for the client connection\n");

    bzero((char*)&clientaddr,sizeof(clientaddr));
    len=sizeof(clientaddr);

    while(1){
   
        recvfrom(serversocket,a,sizeof(a),0,(struct sockaddr*)&clientaddr,&len);
        recvfrom(serversocket,b,sizeof(b),0,(struct sockaddr*)&clientaddr,&len);


        printf("\nConnection received from client.\n");


        printf("\nThe client has send:\t%s\n",a);
        printf("\nThe client has send:\t%s\n",b);   
        
        k[0] = '\0';  // Initialize the result string.

        int sum = atoi(a) + atoi(b);  // Perform integer addition.

        sprintf(k, "%d", sum);  // Convert the integer result to string.

        printf("\nSending message to the client.\n");
        sendto(serversocket,k,sizeof(k),0,( struct sockaddr*)&clientaddr,sizeof(clientaddr));

    }
    close(serversocket);
}



