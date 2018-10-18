#include "chatconnection.hpp"

ChatConnection::ChatConnection(io_service& service)
    :socket{service} {

}

tcp::socket& ChatConnection::getSocket() {
    return this->socket;
}
