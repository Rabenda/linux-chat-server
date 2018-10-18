#include <iostream>
#include <boost/asio.hpp>

#include "chatserver.hpp"

using namespace std;
using namespace boost::asio;

#define SERVER_PORT 12412

int main()
{
    io_service service;
    ChatServer server{service, SERVER_PORT};
    server.start();
    service.run();
    return 0;
}
