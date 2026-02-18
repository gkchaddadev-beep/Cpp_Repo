#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    // 1. Create a socket (AF_INET for IPv4, SOCK_STREAM for TCP)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    address.sin_port = htons(8080);      // Port number (host to network short)

    // 2. Bind the socket to the address and port
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    // 3. Start listening for incoming connections
    listen(server_fd, 3);
    std::cout << "Server listening on port 8080..." << std::endl;

    // 4. Accept a connection from a client
    int client_socket = accept(server_fd, nullptr, nullptr);
    
    // 5. Read data from client
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::cout << "Client says: " << buffer << std::endl;

    // 6. Send a response
    const char* hello = "Hello from server";
    send(client_socket, hello, strlen(hello), 0);

    close(client_socket);
    close(server_fd);
    return 0;
}
