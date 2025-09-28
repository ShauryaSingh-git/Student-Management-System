#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <string>

using namespace std;

// student login--login and signup
// teacher login--login and signup
// admin login  --login and signup
// exit

// user.txt Format --> username,password,email --> everything is comma seperated and next user is found in the next line of the user file
void studentSignup()
{
    fstream file("StudentUser.txt", ios::app | ios::out);
    string username, password, email;
    bool isRegistered = false;
    bool validEmail = false;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    while (password.length() < 6 || password.find(' ') != string::npos)
    {
        cout << "Password must be at least 6 characters long. Please try again." << endl;
        cout << "Enter password: ";
        cin >> password;
    }

    while (validEmail == false)
    {
        cout << "Enter email: ";
        cin >> email;
        if (email.find('@') != string::npos && email.find('.') != string::npos)
        {
            validEmail = true;
        }
        else
        {
            cout << "Invalid email format. Please try again." << endl;
        }
    }
    file << username << "," << password << "," << email << endl;
    file.close();
}

void teacherSignup()
{
    fstream file("TeacherUser.txt", ios::app);
    string username, password, email;
    bool isRegistered = false;
    bool validEmail = false;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    while (password.length() < 6 || password.find(' ') != string::npos || password.find("1234567890") != string::npos)
    {
        cout << "Password must be at least 6 characters long. Please try again." << endl;
        cout << "Enter password: ";
        cin >> password;
    }
    while (validEmail == false)
    {
        cout << "Enter email: ";
        cin >> email;
        if (email.find('@') != string::npos && email.find('.') != string::npos)
        {
            validEmail = true;
        }
        else
        {
            cout << "Invalid email format. Please try again." << endl;
        }
    }
    file << username << "," << password << "," << email << endl;
}

void studentLogin()
{
    ifstream file("StudentUser.txt", ios::in);
    string username, password, email, line;
    bool isRegistered = false;
    while (isRegistered == false)
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        while (getline(file, line))
        {
            if (line == username + "," + password + "," + email)
            {
                isRegistered = true;
                cout << "Login successful!" << endl;
                break;
            }
        }
        file.clear();
        file.seekg(0, ios::beg);
        if (isRegistered == false)
        {
            cout << "Invalid credentials. Please try again." << endl;
        }
    }
    file.close();
}

void teacherLogin()
{
    ifstream file("TeacherUser.txt", ios::in);
    string username, password, email, line;
    bool isRegistered = false;
    while (isRegistered == false)
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        while (getline(file, line))
        {
            if (line == username + "," + password + "," + email)
            {
                isRegistered = true;
                cout << "Login successful!" << endl;
                break;
            }
        }
        file.clear();
        file.seekg(0, ios::beg);
        if (isRegistered == false)
        {
            cout << "Invalid credentials. Please try again." << endl;
        }
    }
    file.close();
}

int main()
{
    // studentSignup();
    studentLogin();
    return 0;
}