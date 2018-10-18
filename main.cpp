#include <iostream>
#include <boost/asio.hpp>

#include "chatserver.hpp"

using namespace std;
using namespace boost::asio;

#define SERVER_PORT 12412

#define BUFFERSIZE 4096

int main()
{
    io_service service;
    ChatServer server{service, SERVER_PORT};

}
