#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[])
{

  int fd, newFd;

  struct sockaddr_in client; /// initiating  s socket struct to store the socket info
  struct hostent *server;    //// we initiate a struct for the host info
  ///////////////////////////////////////////////////
  char buffer[255]; /// array char to store the strings
  /////////////////////////////////////////////////////////////////////////
  if (argc < 3)
  {
    fprintf(stderr, "you have not  provided  enough args(hostname/ ipaddr/ port)... !!!\n");
    exit(1);
  }
  /////////////////////////////////////

  int port;
  port = atoi(argv[2]);
  /////////////////////////////////////////////////

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0)
  {
    printf("error opening the socket !!!!! \n");
  }
  ///////////////////////////////////////
  server = gethostbyname(argv[1]);
  if (server == NULL)
  {
    printf("there is no such host ....\n");
  }

  /////////////////////////////////////////////////// we fill the socket client with inf
  bzero((char *)&client, sizeof(client));
  client.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&client.sin_addr.s_addr, server->h_length);
  client.sin_port = htons(port);

  ////////////////////////////////////////////// we initiate the connection from this socket
  int con;
  con = connect(fd, (struct sockaddr *)&client, sizeof(client));

  if (con < 0)
  {
    printf("connection failed \n");
  }
  ////////////////////////////////////////////////////
  int n;
  while (1)
  {

    bzero(buffer, 255);
    fgets(buffer, 255, stdin);
    ////////////////////////////
    n = write(fd, buffer, strlen(buffer));
    if (n < 0)
    {
      printf("writing failed\n");
    }

    //////////////////////////////////////
    bzero(buffer, 255);
    n = read(fd, buffer, 255);
    if (n < 0)
    {
      printf("reading is failed");
    }
    //////////////////////////////
    printf("msg==> %s", buffer);
    //////////////////////////////////
    int finish;
    finish = strncmp("bye", buffer, 3);
    if (finish == 0)
    {
      break;
    }
  }
  close(fd);

  return 0;
}