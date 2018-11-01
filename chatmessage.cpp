#include "chatmessage.hpp"
#include <sstream>
#include <utility>
#include <string>
using std::stringstream;
using std::copy;
using boost::property_tree::ptree;
using boost::property_tree::write_json;
using boost::property_tree::read_json;
using std::string;
ChatMessage::ChatMessage()
{

}
void ChatMessage::encodeJson(ptree& root) {
    stringstream stream;
    write_json(stream, root, false);
    auto const& streamString = stream.str();
    copy(streamString.cbegin(), streamString.cend(), buffer);
    messageLength = streamString.length();
}

ptree ChatMessage::decodeJson() {
    ptree root;
    stringstream stream{string{buffer, messageLength}};
    read_json(stream, root);
    return root;
}
