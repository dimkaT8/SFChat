#include "Users.h"

User::User(const string user, const string password, const string name)
{
    _user = user;
    _password = password;
    _name = name;

}

string User::get_name()
{
    return _name;
}

string User::get_user()
{
    return _user ;
}

string User::get_password()
{
    return _password ;
}


void User::add_user(const string user, const string password, const string name)
{
    _user = user;
    _password = password;
    _name = name;
}
