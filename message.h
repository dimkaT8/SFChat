#pragma once
#include <string>
#include "Array/array.h"

class Message
{
private:
    Array<string> _message{0};
    Array<int> _fromUser{0};
    Array<int> _toUser{0};
public:
    Message(const string message);
    string get_message(const int pos);
    int get_from(const int pos);
    int get_to(const int pos);
    void add_message(const string m_str, const int m_from, const int m_to);
    int message_size();
};