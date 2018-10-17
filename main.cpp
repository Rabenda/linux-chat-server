#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;

#define SERVER_PORT 12412

#define BUFFERSIZE 4096

size_t read_complete(char * buff, const error_code & err, size_t bytes) {
    if ( err) return 0;
    bool found = std::find(buff, buff + bytes, '\n') < buff + bytes;
    // 我们一个一个读取直到读到回车，不缓存
    return found ? 0 : 1;
}

int main()
{
    io_service service;
    ip::tcp::acceptor acceptor{service, ip::tcp::endpoint{ip::tcp::v4(), SERVER_PORT}};

    char stringBuffer[BUFFERSIZE];
    while (true) {
        ip::tcp::socket socket{service};
        acceptor.accept(socket);
        size_t byteCounts =read(socket, buffer(stringBuffer),
             boost::bind(read_complete,stringBuffer,_1,_2));
        std::string str(stringBuffer, byteCounts);
        cout << str << endl;
        socket.write_some(buffer(str));
        socket.close();
    }

}
