#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 1024
#define UDS_FILE "/tmp/sock.uds"

int main(void) {
    int create_socket, new_socket;
    socklen_t addrlen;
    char buffer[BUF + 1];
    ssize_t size;
    struct sockaddr_un address;
    
    printf("\e[2J");
    
    if ((create_socket = socket(AF_LOCAL, SOCK_STREAM, 0)) > 0)
        printf("Socket wurde angelegt\n");
    
    unlink(UDS_FILE);

    address.sun_family = AF_LOCAL;
    
    strcpy(address.sun_path, UDS_FILE);

    if (bind(create_socket, (struct sockaddr*)&address, sizeof(address)) != 0) {
        printf("Port ist nicht frei!\n");
    }
    
    listen(create_socket, 5);
    addrlen = sizeof(struct sockaddr_in);
    
    while (1) {
        new_socket = accept(create_socket,
                            (struct sockaddr*)&address,
                            &addrlen);
        
        if (new_socket > 0)
            printf("Ein client ist verbunden ...\n");

        do {
            printf("Nachricht zum versenden: ");
            fgets(buffer, BUF, stdin);
            send(new_socket, buffer, strlen(buffer), 0);
            size = recv(new_socket, buffer, BUF-1, 0);
            
            if (size > 0)
                buffer[size] = '\0';
            
            printf("Nachricht empfangen: %s\n", buffer);
        } while (strcmp(buffer, "quit\n") != 0);

        close(new_socket);
    }
    
    close(create_socket);

    return EXIT_SUCCESS;
}
