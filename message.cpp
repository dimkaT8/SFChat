#include "message.h"


Message::Message(const string message)
{
    _message.insert(message,0);
    _fromUser.insert(0,0);
    _toUser.insert(-1,0);
}

string Message::get_message(const int pos)
{
    return _message[pos];
}

int Message::get_from(const int pos)
{
    return _fromUser[pos];
}

int Message::get_to(const int pos)
{
    return _toUser[pos];
}

void Message::add_message(const string m_str, const int m_from, const int m_to)
{
    _message.push_back(m_str);
    _fromUser.push_back(m_from);
    _toUser.push_back(m_to);
}

int Message::message_size()
{
    return _message.size();
}