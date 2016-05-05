#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include<pthread.h> //for threading , link with lpthread
#include<iostream>
#include <time.h> // for time
using namespace std;

//the thread function
struct ThreadData
{
    char key[64];
    unsigned long int t_no;
};
int client_sock[2];
void *connection_handler(void *);

int main()
{
    int socket_desc, c;
    struct sockaddr_in server , client;

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        puts("Can't not create socket");
    }
    puts("Socket created!!!!");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3333);

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind failed\n");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    c = sizeof(struct sockaddr_in);
    pthread_t thread_id[8];
    char *key;
   int i=0;
   while(i<2)
   {
        client_sock[i] = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if(client_sock[i] == -1){
                printf("can't accept sockets returing");
                return 0;
        }

        if( pthread_create( &thread_id[i] , NULL ,  connection_handler , (void*) &client_sock[i]) < 0)
        {
            puts("could not create thread");
            return 1;
        }
        printf("Client Number: %d\n",i);
        puts("Handler assigned \n");
        i++;
   }
   time_t start, end;
   double timediff;
   int j=i-1;
   while(j>=0){
        pthread_join(thread_id[j--],(void **)&key);
	printf("thread %d:\n",j);//puts("key");
	if(key!=NULL && key[0]!=' '){
		break;
	}
   }

   //time(&start);
   //time(&end);
   //timediff = difftime(end, start);
   //printf("took %.f seconds to crack DES Key\n", timediff);

   puts("out of client accepting loop\n");
  /* while(i>0){
        //puts("closing clientsocket:");
        //puts("\n");
        //cout<<thread_id[i-1];
        write(client_sock[i-1] , "close" ,6);
	close(client_sock[i-1]);
	pthread_cancel(thread_id[i-1]);
	i--;
    }*/
    //exit(0);
    return 0;
}

/*
 * This will handle connection for each client
 * */
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int size;
    char key[100];
    char *message , client_message[100];
    //memset(client_message,' ',65);

    //Receive a message from client
    size = recv(sock , client_message , 100 , 0);
    client_message[size]='\0';
    puts(client_message);
    puts("after printing client message\n");
    memset(key,' ',64);
    strcpy(key, client_message);
    key[size]='\0';
    memset(client_message,' ',size);
    puts("printing clientmesage\n");
    puts(client_message);
    puts("\n");
    puts("printing key");
    puts(key);
    puts("\n");
    if(key[0]==' '){
	puts("key is empty");
        pthread_exit(NULL);
    }
    else{
	puts("returned key");
	for(int i=0;i<2;i++){
		write(client_sock[i] , "close" ,6);
		cout<<client_sock[i]<<"\t SockID";
	}
        close(sock);
        exit(0);
    }

        //return NULL;
        //return (void*)td;
}
