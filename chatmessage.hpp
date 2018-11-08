#ifndef CHATMESSAGE_HPP
#define CHATMESSAGE_HPP

#include <memory>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class ChatMessage
{

public:
    ChatMessage();
     ChatMessage(char* messageBuffer, size_t messageSize);

    void encodeJson(boost::property_tree::ptree& root);
    boost::property_tree::ptree decodeJson();
private:
    constexpr static size_t MESSAGE_LENGTH = 4096;
    char buffer[MESSAGE_LENGTH];
    size_t messageLength;
};

#endif // CHATMESSAGE_HPP
