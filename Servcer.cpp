#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

#define BUFSIZE 1024

int main() {
    int server_id, client_id;
    struct sockaddr_in server_address, client_address;
    socklen_t client_length = sizeof(client_address);
    char buffer[BUFSIZE];
    const char *response = "Hello, Client!";

    // Create a socket
    server_id = socket(AF_INET, SOCK_STREAM, 0);
    if (server_id < 0) {
        cout << "Socket creation failed...\n";
        return -1;
    } else {
        cout << "Socket successfully created...\n";
    }

    // Set up server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080); // Port number
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept connections on any address

    // Bind the socket to the address and port
    if (bind(server_id, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        cout << "Socket bind failed...\n";
        close(server_id);
        return -1;
    } else {
        cout << "Socket successfully bound...\n";
    }

    // Listen for incoming connections
    if (listen(server_id, 5) < 0) {
        cout << "Listening failed...\n";
        close(server_id);
        return -1;
    } else {
        cout << "Server is listening for connections...\n";
    }

    // Accept a connection
    client_id = accept(server_id, (struct sockaddr *)&client_address, &client_length);
    if (client_id < 0) {
        cout << "Server accept failed...\n";
        close(server_id);
        return -1;
    } else {
        cout << "Server accepted a client...\n";
    }

    // Receive a message from the client
    int bytes_received = recv(client_id, buffer, BUFSIZE - 1, 0);
    if (bytes_received < 0) {
        cout << "Receiving data failed...\n";
    } else {
        buffer[bytes_received] = '\0';
        cout << "Client message: " << buffer << "\n";
    }

    // Send a response to the client
    send(client_id, response, strlen(response), 0);
    cout << "Response sent: " << response << "\n";

    // Close the sockets
    close(client_id);
    close(server_id);

    cout << "Server closed.\n";
    return 0;
}
