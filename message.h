#pragma once
#include <string>
using namespace std;

class Message
{
 private:
    int _fromUser;
    int _toUser;
    string _message;

 public:
    Message(const string m_message, const int m_from, const int m_to);
    string get_message();
    int get_from();
    int get_to();

};