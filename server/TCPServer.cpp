#include "TCPServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

void TCPServer::run()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    bind(server_fd, (sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 5);

    std::cout << "[Server] Listening on port " << port << "...\n";

    while (true)
    {
        int clientSocket = accept(server_fd, nullptr, nullptr);
        if (clientSocket < 0)
        {
            std::cerr << "[Server] Failed to accept connection\n";
            continue;
        }

        // Thay đổi: giữ kết nối với client cho đến khi client đóng
        while (true)
        {
            char buffer[2048] = {0};
            int len = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (len <= 0)
            {
                // Client đóng kết nối hoặc lỗi
                break;
            }
            std::string input(buffer, len);

            //! ---------------------------------------------------------
            Response res;
            try
            {
                Request req = RequestParser::parse(input);
                std::cout << "Request --------------------" << endl;
                std::cout << req << endl;
                if (!AuthMiddleware::authorize(req))
                {
                    res = Response::unauthorized();
                }
                else
                {
                    auto controller = Router::getController(req);
                    if (controller)
                    {
                        res = controller->handle(req);
                    }
                    else
                    {
                        res = Response::error();
                    }
                }
            }
            catch (const std::exception &e)
            {
                res = Response::error();
            }
            std::cout << "List TOKEN: " << TokenStore::instance();
            std::cout << "Response --------------------" << endl;
            std::string output = res.toCS23Format() + "\n";
            std::cout << "END --------------------" << endl;
            //! ---------------------------------------------------------

            send(clientSocket, output.c_str(), output.size(), 0);
        }
        close(clientSocket);
    }

    close(server_fd);
}
