#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <systemd/sd-journal.h>

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    sd_journal_print(LOG_INFO, "REST API Server started on port 8080");

    while (true)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);

        sd_journal_print(LOG_INFO, "HTTP request received");

        const char *response =
            "HTTP/1.1 200 OK\nContent-Type: application/json\n\n"
            "{ \"temperature\": 25, \"light\": \"ON\" }";

        send(new_socket, response, strlen(response), 0);
        close(new_socket);
    }

    return 0;
}
