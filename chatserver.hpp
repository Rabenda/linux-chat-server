#ifndef CHATSERVER_HPP
#define CHATSERVER_HPP

#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <cstdint>
#include <memory>
#include <set>
#include "chatconnection.hpp"
using boost::asio::io_service;
using boost::asio::ip::tcp;
using boost::system::error_code;
using std::shared_ptr;
using std::set;
using std::enable_shared_from_this;
class ChatServer: private boost::noncopyable
{
public:
    explicit ChatServer(io_service& service, uint16_t port);
    ~ChatServer();
    void start();
    void join(shared_ptr<ChatConnection> connection);
    void leave(shared_ptr<ChatConnection> connection);
private:
    io_service& service;
    tcp::acceptor acceptor;
    set<shared_ptr<ChatConnection>> connectionList;
};

#endif // CHATSERVER_HPP
