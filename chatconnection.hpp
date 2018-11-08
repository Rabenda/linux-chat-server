#ifndef CHATCONNECTION_HPP
#define CHATCONNECTION_HPP

#include <memory>
#include <boost/asio.hpp>
#include "chatmessage.hpp"
#include "serverconfig.hpp"
class ChatServer;

class ChatConnection: public std::enable_shared_from_this<ChatConnection> {
public:
    explicit ChatConnection(boost::asio::io_service& service, ChatServer* server);

    boost::asio::ip::tcp::socket& getSocket();

    void start();
private:
    void readHandler(const boost::system::error_code &e, std::size_t s);
    boost::asio::ip::tcp::socket socket;
    ChatServer* server;
    boost::asio::streambuf buffer;
};

#endif // CHATCONNECTION_HPP
