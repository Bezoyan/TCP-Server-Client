//TCP client

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main()
{
  //creat a socket
  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  //address for socket
    struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  //connect with server
  int connection_ststus =  connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
  if (connection_ststus == -1)
  {
    std::cout << "there is an error to making connection to the remote socket"<<std::endl; 
  }
  
 //receive data from the server 
  char server_response[256];
  recv(network_socket, &server_response, sizeof(server_response), 0);
  std::cout << server_response << "The server data was sent" <<std::endl;
  
//close the socket
int close(network_socket);
  return 0;
  
  
}