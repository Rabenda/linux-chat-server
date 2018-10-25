#include <boost/asio.hpp>
#include "serverconfig.hpp"
#include "chatserver.hpp"

using boost::asio::io_service;

int main()
{
    io_service service;
    ChatServer server{service, SERVER_PORT};
    server.start();
    service.run();
    return 0;
}
