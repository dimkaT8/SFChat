#pragma once
#include <string>
using namespace std;

class User
{
private:
    string _user;
    string _password;
    string _name;
public:
    User(const string user , const string password , const string name );
    string get_name();
    string get_user();
    string get_password();
    void add_user(const string user , const string password , const string name);
};