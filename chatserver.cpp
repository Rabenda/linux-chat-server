#include "chatserver.hpp"
#include <boost/log/trivial.hpp>

ChatServer::ChatServer(io_service& service, uint16_t port)
    :service{service}, acceptor{this->service, tcp::endpoint{tcp::v4(), port}} {

}

ChatServer::~ChatServer() {
    connectionList.clear();
}

void ChatServer::start() {
    auto chatConnectionPtr = std::make_shared<ChatConnection>(service, this);
    acceptor.async_accept(chatConnectionPtr->getSocket(),
                          [chatConnectionPtr, this]
                          (error_code const& errorCode) {
        if(errorCode) {
            BOOST_LOG_TRIVIAL(warning) <<"accept err:"<<errorCode.message()<<"\n";
            return;
        }
        chatConnectionPtr->start();
        this->start();
    });
}

void ChatServer::join(shared_ptr<ChatConnection> connection) {
    BOOST_LOG_TRIVIAL(info) << " new connection join" <<"\n";
    connectionList.insert(connection);
}

void ChatServer::leave(shared_ptr<ChatConnection> connection) {
    BOOST_LOG_TRIVIAL(info) << " connection leave" <<"\n";
    auto removeConnectionIterator = connectionList.find(connection);
    connectionList.erase(removeConnectionIterator);
}
