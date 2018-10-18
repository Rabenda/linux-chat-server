#include "chatconnection.hpp"

ChatConnection::ChatConnection(io_service& service)
    :socket{service} {

}
