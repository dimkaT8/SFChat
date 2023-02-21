#pragma once
#include <string>
#include "Array/array.h"
using namespace std;

class User
{
private:
    Array<string> _user{0};
    Array<string> _password{0};
    Array<string> _name{0};
public:
    User(const string user , const string password , const string name );
    string get_name(const int pos);
    string get_user(const int pos);
    string get_password(const int pos);
    void add_user(const string user , const string password , const string name);
    int array_size();
};