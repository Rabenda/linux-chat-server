#ifndef CHATCONNECTION_HPP
#define CHATCONNECTION_HPP

#include <memory>
#include <boost/asio.hpp>
#include "chatmessage.hpp"

class ChatServer;

class ChatConnection: public std::enable_shared_from_this<ChatConnection> {
public:
    explicit ChatConnection(boost::asio::io_service& service, ChatServer* server);

    boost::asio::ip::tcp::socket& getSocket();

    void start();
private:
    boost::asio::ip::tcp::socket socket;
    ChatServer* server;
    ChatMessage message;

};

#endif // CHATCONNECTION_HPP
