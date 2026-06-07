#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    // 1. create blank socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. allow port reuse (quality of life — avoids "address already in use")
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 3. bind to port 6379
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6379);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(server_fd, (sockaddr*)&addr, sizeof(addr));

    // 4. start listening
    listen(server_fd, 128);
    std::cout << "Server listening on port 6379...\n";

    // 5. accept loop
    while (true) {
        int conn_fd = accept(server_fd, nullptr, nullptr);

        char buf[256] = {};
        read(conn_fd, buf, sizeof(buf));
        std::cout << "Got: " << buf << "\n";

        std::string response = "Hello from server!\n";
        write(conn_fd, response.c_str(), response.size());

        close(conn_fd);
    }
}