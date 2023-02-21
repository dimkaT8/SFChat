#include <iostream>
#include "Users.h"
#include "message.h"
#include <vector>

void RegistrationUser(vector<User> *us)
{
    string var_user{};
    string var_name{};
    string var_password{};
    cout << " Registration User " <<endl;
    cout << " User : "; cin >> var_user;
    cout << " Password : "; cin >> var_password;
    cout << " NickName : "; cin >> var_name;
    us->push_back(User(var_user,var_password,var_name));
}

int Authentication(vector<User> *us , string str)
{
    int number_of_people = {-1} ;
    for(int i=0 ; i < us->size(); i++)
    {
      if(str == us->at(i).get_user()) number_of_people = i;
    }
    if(number_of_people < 0 ) return -1 ;

    string var_password{};
    cout << " Password : "; cin >> var_password;

    if(var_password == us->at(number_of_people).get_password())
        return number_of_people;
    return -1 ;
}

 int main()
 {
   vector<User> user ;
   vector<Message> mess;
   user.push_back(User("admin","admin","admin"));
   mess.push_back(Message(" Welcome to chat",0,-1));

   cout << " Register at least three users" << endl;
   string var_string{"Y"};
 
 while (var_string == "Y")
    {
        RegistrationUser(&user);
        cout << endl <<" continue on ? Yes(Y) No(N) :"; cin >> var_string;
        cout << endl;
    }

    var_string = "N";
    while(var_string == "N")
    {
      cout << " Registered : " ;
      int number_of_people {-1} ;
      cout << "\033[1;42m"; 
      while(number_of_people == -1)
        {
             for(int i=0 ; i < user.size(); i++)
                    cout << user.at(i).get_user() << " " ;

             cout << "\033[0m\n" << endl << endl;
             cout << " which user to choose ? : "; cin >> var_string;
             number_of_people = Authentication( &user , var_string);
             if(number_of_people < 0 ) cout << " Wrong login or password " << endl ;
        }
      
      cout << user.at(number_of_people).get_name() << endl;

      for(int i=0 ; i < mess.size();i++)
        {
            cout << endl;
            if(mess.at(i).get_from() == number_of_people)
            {
                cout << " \033[1;32m" << user.at(number_of_people).get_name() << " >>>>> " ;
                if(mess.at(i).get_to() < 0)
                {
                    cout << "All" << endl;
                } else cout << user.at(mess.at(i).get_to()).get_user();

                cout << "\033[0m\n"<< mess.at(i).get_message() << endl ;
            }

            if((mess.at(i).get_to() == number_of_people) || (mess.at(i).get_to() == -1))
            {
                cout << "\t \033[1;32m" << user.at(number_of_people).get_name() << " <<<<<< " ;
                cout << user.at(mess.at(i).get_from()).get_user() << "\033[0m\n" <<endl;
                cout << "\t" << mess.at(i).get_message() << endl;
            }
        }

        cout << endl;
        var_string = "Y";

        while(var_string == "Y")
        {
             cout << endl << " Who do you want to send a message to ?" << endl ;
             cout << "\033[1;42m";
             for(int i=0 ; i < user.size(); i++)
                    cout << user.at(i).get_user() << " " ;
             cout << "ALL \033[0m\n" << endl ; cin >> var_string;

             int out_user=-1;
             for(int i=0 ; i < user.size(); i++)
                 if(user.at(i).get_user() == avar_string) out_user = i;
             cout << endl ;
             cout << " Message : " ;

             while (getline(cin, var_string)) if (var_string != "") break;

             mess.push_back(Message(var_string , number_of_people , out_user));
             cout << " write further ? Yes(Y)  No(N) : " ;
             cin >> var_string;

        }

        cout << endl <<" Exit from the program ? Yes(Y) No(N) :";
        cin >> var_string; 
    }
   return 0;
 }