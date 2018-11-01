#include "chatconnection.hpp"
#include <boost/log/trivial.hpp>
#include "chatserver.hpp"
using boost::asio::io_service;
using boost::asio::ip::tcp;
using std::enable_shared_from_this;
ChatConnection::ChatConnection(io_service& service, ChatServer* server)
    :socket{service}, server{server} {

}

tcp::socket& ChatConnection::getSocket() {
    return this->socket;
}

void ChatConnection::start() {
    BOOST_LOG_TRIVIAL(debug) << __FUNCTION__ <<"\n";
    server->join(shared_from_this());
//    boost::asio::async_read(getSocket(),

//                            )
}
