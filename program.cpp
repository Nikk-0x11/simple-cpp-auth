#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// validation check
string uname;
int temp;
void validationCheck(string str)
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        return;
    }
    else
    {
        temp++;
        if (temp == 3)
        {
            cout << "username already exists. Try Again." << endl;
            return;
        }
        cout << "username already exists.\nCreate another user: ";
        cin >> uname;
        validationCheck(uname);
    }
}

// main function
int main()
{
    int choice, i, exit = 0;
    string ans, pass, name, fname, bio, usrname, passwd, line, newUsrname;
    ofstream fileout;
    ifstream filein;
    cout << "Welcome to catto auth system!" << endl;
    while (exit == 0)
    {
        cout << "\nChoose an option:\n1. LogIn [Press 1]\n2. SignUp [Press 2]\npress any key and enter to exit." << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter your username: ";
            cin >> uname;
            cout << "Enter your password: ";
            cin >> pass;
            fname = uname + ".txt";
            filein.open(fname.c_str());
            if (!filein.is_open() && filein.fail())
            {
                cout << "\nInvalid credentials, register before logging in." << endl;
                filein.close();
                continue;
            }
            getline(filein, usrname);
            getline(filein, line);
            getline(filein, passwd);
            if (uname == usrname && pass == passwd)
            {
                cout << "\nLogin Success!\nProfile Details ->" << endl;
                cout << "username: " << usrname << endl;
                cout << "name: " << line << endl;
                getline(filein, line);
                cout << "Bio: " << line << endl;
                filein.close();
            }
            else
            {
                cout << "\nWrong username or password.\nTry Again!" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "\nEnter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter a username: ";
            cin >> uname;
            temp = 0;
            validationCheck(uname);
            if (temp >= 3)
            {
                continue;
            }
            cout << "Enter a password: ";
            cin >> pass;
            fname = uname + ".txt";
            fileout.open(fname.c_str());
            fileout << uname << endl;
            fileout << name << endl;
            fileout << pass << endl;
            cout << "\nRegistration Success." << endl;
            cout << "\nEnter a few words about yourself and press enter when done.\n";
            cout << "About: ";
            cin.ignore();
            getline(cin, bio);
            fileout << bio << endl;
            cout << "Your AboutMe: " << bio << endl;
            fileout.close();
        }
        else{
            exit = 1;
        }
    }
    cout << "\nARIGATO!\n";
}