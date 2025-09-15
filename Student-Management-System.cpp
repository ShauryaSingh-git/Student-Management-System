#include<iostream>
#include<vector>
#include<unordered_set>
#include<fstream>
#include<string>

using namespace std;

//student login--login and signup
//teacher login--login and signup
//admin login  --login and signup
//exit

void studentSignup()
{
    fstream file("user.txt",ios::app);
    string username,password,email;
    bool isRegistered=false;
    bool validEmail=false;

    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    while(password.length()<6||password.find(' ')!=string::npos||password.find("1234567890")!=string::npos))
    {
        cout<<"Password must be at least 6 characters long. Please try again."<<endl;
        cout<<"Enter password: ";
        cin>>password;
    }
 
    while(validEmail==false)
    {
    cout<<"Enter email: ";
    cin>>email;
    if(email.find('@')!=string::npos && email.find('.')!=string::npos && )
    {
        validEmail=true;
    }
    else
    {
        cout<<"Invalid email format. Please try again."<<endl;
    }
    
    
    }
    file<<username<<","<<password<<","<<email<<endl;
}

void teacherSignup()
{
    fstream file("user.txt",ios::app);
    string username,password,email;
    bool isRegistered=false;
    bool validEmail=false;

    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    while(password.length()<6||password.find(' ')!=string::npos||password.find("1234567890")!=string::npos))
    {
        cout<<"Password must be at least 6 characters long. Please try again."<<endl;
        cout<<"Enter password: ";
        cin>>password;
    }
 
    while(validEmail==false)
    {
    cout<<"Enter email: ";
    cin>>email;
    if(email.find('@')!=string::npos && email.find('.')!=string::npos)
    {
        validEmail=true;
    }
    else
    {
        cout<<"Invalid email format. Please try again."<<endl;
    }

    }
file<<username<<","<<password<<","<<email<<endl;
}

void studentLogin()
{
    fstream file("")
}