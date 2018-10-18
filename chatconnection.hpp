#ifndef CHATCONNECTION_HPP
#define CHATCONNECTION_HPP

#include <memory>
#include <boost/asio.hpp>

using boost::asio::io_service;
using boost::asio::ip::tcp;

class ChatConnection:
        public std::enable_shared_from_this<ChatConnection> {
public:
    explicit ChatConnection(io_service& service);

    tcp::socket& getSocket();
private:
    tcp::socket socket;
};

#endif // CHATCONNECTION_HPP
