#include "user.h"
#include "message.h"

void RegistrationUser(User *us)
{
    string var_user{};
    string var_name{};
    string var_password{};
    cout << " Registration User " <<endl;
    cout << " User : "; cin >> var_user;
    cout << " Password : "; cin >> var_password;
    cout << " NickName : "; cin >> var_name;
    us->add_user(var_user,var_password,var_name);
}

int Authentication(User *us , string str)
{
    int number_of_people = {-1} ;
    for(int i=0 ; i < us->array_size(); i++)
    {
        if( str == us->get_user(i)) number_of_people = i;
    }
    if(number_of_people < 0 ) return -1 ;

    string var_password{};
    cout << " Password : "; cin >> var_password;

    if(var_password == us->get_password(number_of_people))
        return number_of_people;
    return -1 ;
}

int main()
{
    User *us = new User("admin","admin","admin");
    Message *mess = new Message(" Welcome to chat ");

    cout << " Register at least three users" << endl; // Зарегистрируйте не менее трех пользователей
    string var_string{"Y"};

    while (var_string == "Y")
    {
        RegistrationUser(us);
        cout << endl <<" continue on ? Yes(Y) No(N) :"; cin >> var_string; // продолжать
        cout << endl;
    }
    var_string = "N";
    while(var_string == "N")
    {
        cout << " Registered : " ;
        int number_of_people {-1} ;
        cout << "\033[1;42m"; // 32 42
        while(number_of_people == -1)
        {
             for(int i=0 ; i < us->array_size(); i++)
                    cout << us->get_user(i) << " " ;

             cout << "\033[0m\n" << endl << endl;
             cout << " which user to choose ? : "; cin >> var_string; // какого пользователя выбрать
             number_of_people = Authentication( us , var_string);
             if(number_of_people < 0 ) cout << " Wrong login or password " << endl ; // неверный логин или пароль
        }
        
        cout << us->get_name(number_of_people) << endl;
        // display messages if any
        for(int i=0 ; i < mess->message_size();i++)
        {
            cout << endl;
            if(mess->get_from(i) == number_of_people)
            {
                cout << " \033[1;32m" << us->get_name(number_of_people) << " >>>>> " ;
                if(mess->get_to(i) < 0 )
                {
                    cout << "All" << endl;
                } else cout << us->get_user(mess->get_to(i)) << endl ;

                cout << "\033[0m\n"<< mess->get_message(i) << endl ;
            }

            if((mess->get_to(i) == number_of_people) || (mess->get_to(i) == -1))
            {
                cout << "\t \033[1;32m" << us->get_name(number_of_people) << " <<<<<< " ;
                cout << us->get_user(mess->get_from(i)) << "\033[0m\n" <<endl;
                cout << "\t" << mess->get_message(i) << endl;
            }
        }
        cout << endl;
        var_string = "Y";
        while(var_string == "Y")
        {
             cout << endl << " Who do you want to send a message to ?" << endl ;
             cout << "\033[1;42m";
             for(int i=0 ; i < us->array_size(); i++)
                    cout << us->get_user(i) << " " ;
             cout << "ALL \033[0m\n" << endl ; cin >> var_string;

             int out_user=-1;
             for(int i=0 ; i < us->array_size(); i++)
                 if(us->get_user(i)==var_string) out_user = i;
             cout << endl ;
             cout << " Message : " ; 

             while (getline(cin, var_string)) if (var_string != "") break;

             mess->add_message(var_string , number_of_people , out_user);
             cout << " write further ? Yes(Y)  No(N) : " ;
             cin >> var_string;

        }
        cout << endl <<" Exit from the program ? Yes(Y) No(N) :";
        cin >> var_string;
    }

    delete us;
    delete mess;
    return 0;
}