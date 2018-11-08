#include "chatconnection.hpp"
#include <boost/log/trivial.hpp>
#include "chatserver.hpp"
#include <string>

using boost::asio::io_service;
using boost::asio::ip::tcp;
using std::enable_shared_from_this;
ChatConnection::ChatConnection(io_service &service, ChatServer *server)
    : socket{service}, server{server}
{
}

tcp::socket &ChatConnection::getSocket()
{
    return this->socket;
}

void ChatConnection::start()
{
    BOOST_LOG_TRIVIAL(debug) << __FUNCTION__ << "\n";
    server->join(shared_from_this());
    boost::asio::async_read_until(getSocket(),
                                  buffer,
                                  MESSAGE_END_STRING,
                                  [this](const error_code &e, std::size_t s) {
                                      this->readHandler(e, s);
                                  }

    );
}

void ChatConnection::readHandler(const error_code &e, std::size_t s)
{

    boost::asio::async_read_until(getSocket(),
                                  buffer,
                                  MESSAGE_END_STRING,
                                  [this](const error_code &e, std::size_t s) {
                                      this->readHandler(e, s);
                                  });
}
