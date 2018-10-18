#ifndef CHATSERVER_HPP
#define CHATSERVER_HPP

#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>

#include "chatconnection.hpp"
using boost::asio::io_service;
using boost::asio::ip::tcp;
using boost::system::error_code;
class ChatServer: boost::noncopyable
{
public:
    explicit ChatServer(io_service& service, unsigned short port);

    void start();
private:
    io_service& service;
    tcp::acceptor acceptor;
};

#endif // CHATSERVER_HPP
