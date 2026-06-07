#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // 1. create blank socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. connect to server
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6379);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    connect(fd, (sockaddr*)&addr, sizeof(addr));

    // 3. send a message
    std::string msg = "SET foo bar";
    write(fd, msg.c_str(), msg.size());

    // 4. read response
    char buf[256] = {};
    read(fd, buf, sizeof(buf));
    std::cout << "Server says: " << buf << "\n";

    close(fd);
}