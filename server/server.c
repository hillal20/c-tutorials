#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "you have to provide the port number ...!!!\n");
    exit(1);
  }

  ////// we declare some variable
  int fd, newFd, port;
  char buffer[255];

  /////////// we declar the socket structs

  struct sockaddr_in server, client; ///// we are using socket type internet 4 (sockaddr_in)
  socklen_t client_len;              /// socklen_t is  reserved variable  for the ip  address size at least 32 bytes

  ////// we initiate the socket
  fd = socket(AF_INET, SOCK_STREAM, 0); //  AF_INET = IP4v(add family) , SOCK_STREAM = TCP , 0 = default
  if (fd < 0)
  {
    perror("error in opening the socket\n");
  }

  /////  clear any data
  bzero((char *)&server, sizeof(server)); /// clearing data of the struct

  /////////////////
  port = atoi(argv[1]); //// atoi turn string to integer

  //////////////////////// filling the server with the internet and ip address needed
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port); //// htons(host to network short) turns integer to network format (binnay)

  ///////////////////////// we will go for binding now

  int B;
  B = bind(fd, (struct sockaddr *)&server, sizeof(server)); /// we cast server to sockaddr because we start it from sockaddr_in
  if (B < 0)
  {
    printf(" binding has failed ....!!!\n");
  }
  ////////////////////////  we will go to listen now , we need to fill newfd by accepting fd
  listen(fd, 5); /// max of clients to listen at server at the tame
  client_len = (sizeof(client));

  newFd = accept(fd, (struct sockaddr *)&client, &client_len);

  if (newFd < 0)
  {
    perror("error in opening the  newFD socket by accepting \n");
  }

  /////////////// we open the loop to keep the connection persistent between server and client
  int n;
  while (1)
  {
    bzero(buffer, 255); // clearing the buffer
    /////////////////////////////
    n = read(newFd, buffer, 255);
    if (n < 0)
    {
      printf(" error is reading");
    }
    //////////////// printing the message ;
    printf(" msg ====>: %s \n", buffer);
    bzero(buffer, 255);

    fgets(buffer, 255, stdin); /// read the stream and put int the buffer to send it back to the client

    n = write(newFd, buffer, strlen(buffer));
    if (n < 0)
    {
      printf(" error is writing");
    }
    ////////////////// we need to enf the loop;

    int finish;
    finish = strncmp("bye", buffer, 3);
    if (finish == 0)
    {
      break;
    }
  }
  close(newFd);
  close(fd);
  return 0;
}