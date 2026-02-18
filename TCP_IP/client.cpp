#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    // 1. Create a socket
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    // 2. Define the server address (Connecting to localhost 127.0.0.1)
    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // 3. Connect to the server
    if (connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    // 4. Send a message to the server
    const char* message = "Hello from client";
    send(client_fd, message, strlen(message), 0);
    std::cout << "Message sent to server" << std::endl;

    // 5. Read the server's response
    char buffer[1024] = {0};
    int valread = read(client_fd, buffer, 1024);
    std::cout << "Server replied: " << buffer << std::endl;

    // 6. Close the connection
    close(client_fd);
    return 0;
}
