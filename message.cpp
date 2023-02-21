#include "message.h"

Message::Message(const string m_message , const int m_from, const int m_to)
{
    _message = m_message;
    _fromUser = m_from ;
    _toUser = m_to ;
}

string Message::get_message()
{
    return _message;
}

int Message::get_from()
{
    return _fromUser;
}

int Message::get_to()
{
    return _toUser;
}