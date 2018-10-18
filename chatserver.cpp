#include "chatserver.hpp"

ChatServer::ChatServer(io_service& service, unsigned short port)
    :service{service}, acceptor{this->service, tcp::endpoint{tcp::v4(), port}} {

}

void ChatServer::start() {

}
