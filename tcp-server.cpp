TCP server  appliction

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
  //create the server socket
  char server_messege[256] = "You have reached the server";
  int  server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
 
  
  //define address for server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  //bind the socet to our specified IP and port 
 int bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
  int listen(server_socket, 5);
  
  //accept 
  int client_socket;
  client_socket = accept(server_socket, NULL, NULL);
  
  
  //send
  int send(client_socket, server_messege, sizeof(server_messege), 0);
  std::cout<<"sent";
  
  //close the socket
 int close(server_socket);
  
  
  return 0;
}