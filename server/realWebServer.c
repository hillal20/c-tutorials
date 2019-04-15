#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

char webpage[] =
    "HTTP/1.1 OK 200\r\n"
    "Content-type: text/html; charset=UTF-8\r\n\r\n"
    "<html><head><title>HELLO WORD!!!!!!!!!!!!!!!!!!!</title></head><body>MY FIRST WEB BROWSER IN C!!!!!!</body></html>\r\n";
int main(int argc, char *argv[])
{
  struct sockaddr_in server, client;
  socklen_t clength = sizeof(client);
  int fd, newfd;
  char buffer[2048];
  int on = 1;
  ////////////////////  we start the socket of the server
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0)
  {
    perror("opening socket failed\n");
    exit(1);
  }
  /////////////////// set socket options
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int)); // socket , protocol level, option name , option value
  ////////////////////////////////// initialize the server address struct
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(9000);
  //////////////////////////////////////  we bind the socket to the port and ip address
  int b;
  b = bind(fd, (struct sockaddr *)&server, sizeof(server));
  if (b == -1)
  {
    perror(" binding failed \n");
    close(fd);
    exit(1);
  }
  ////////////////////// we listen
  int l;
  l = listen(fd, 10);
  if (l == -1)
  {
    perror(" listeneing error\n");
    close(fd);
    exit(1);
  }
  ////////////////////// starting the actions
  while (1)
  {

    newfd = accept(fd, (struct sockaddr *)&client, &clength);
    if (newfd == -1)
    {
      perror(" can not connect to client\n");
      continue;
    }
    printf(" get client connection\n");
    //////////////////////////// ////////////////////let fork()
    int c;
    c = fork();
    if (c < 0)
    {
      perror(" problem with forking\n");

      exit(1);
    }
    ///// ///////////////////////////////////////////////child process
    if (c == 0)
    {
      memset(buffer, 0, 2048); ///// setthing the memory to buffer array with 0 values
      read(newfd, buffer, 2047);
      // printf("==> buffer : %s\n", buffer);

      write(newfd, webpage, sizeof(webpage) - 1);
      close(newfd);
      // printf("closing .......\n");
      exit(0);
    }
    ////////////////////////////////////////////////////// parent process
    if (c > 0)
    {
      close(newfd);
    }
  }

  return 0;
}