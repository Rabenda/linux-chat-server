#include <iostream>
#include <boost/asio.hpp>

using namespace std;

int main()
{
    boost::asio::io_service service;

    cout << "Hello World!" << endl;
    return 0;
}
