#include "user.h"


User::User(const string user, const string password, const string name)
{
    _user.insert(user,0);
    _password.insert(password,0);
    _name.insert(name,0);

}

string User::get_name(const int pos)
{
    return _name[pos];
}

string User::get_user(const int pos)
{
    return _user[pos] ;
}

string User::get_password(const int pos)
{
    return _password[pos] ;
}


void User::add_user(const string user, const string password, const string name)
{
    _user.push_back(user);
    _password.push_back(password);
    _name.push_back(name);
}

int User::array_size()
{
    return _user.size();
}