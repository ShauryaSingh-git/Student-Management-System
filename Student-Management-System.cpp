#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <functional>

using namespace std;

// student login--login and signup
// teacher login--login and signup
// admin login  --login and signup
// exit
class user{
    protected:
    string username, password, email;
    int marks;
    string hasher(const string& password)
    {
        hash<string> hashh;
        size_t hashed=hashh(password);
        return to_string(hashed);
    }

};
class Student:public user{
    private:
    //studet menu will be in private so that only logged in student can access it
    void studentMenu(const string& username)
{
    cout<<"Student Menu"<<endl;
    cout<<"1. View My Details"<<endl;
    cout<<"2. View My Marks"<<endl;
    cout<<"3. Exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        //it is the section where we will view the details of the students
            break;
        case 2:
        //it is the section where we will view the marks of the students
            break;
        case 3:
        exit(0);
        default:
        cout<<"Invalid choice"<<endl;
        cout<<endl;
        studentMenu(username);
        break;
    }
}

    public:
    
    Student()
    {}
    void studentSignup()
    {
    fstream file("StudentUser.txt", ios::app | ios::out);
    bool validEmail = false;
    bool complete=false;
    
    while(complete==false)
    {
    cout << "Enter username: ";
    cin >> username;

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

    cout << "Enter password: ";
    cin >> password;
    while (password.length() < 6 || password.find(' ') != string::npos)
    {
        cout << "Password must be at least 6 characters long. Please try again." << endl;
        cout << "Enter password: ";
        cin >> password;
    }

    //here we will check if the username or email already exists in the file
    //if it exists the we will prompt the user to enter a diffrent username or email whichever is already exists
    //if both are unique then we will store the data in the file
    ifstream filecheck("StudentUser.txt",ios::in);
    string usernamecheck,emailcheck,line;
    while(getline(filecheck,line))
    {
        stringstream ss(line);
        getline(ss,usernamecheck,',');
        getline(ss,emailcheck,',');
        if(usernamecheck==username)
        {
            cout<<"Username already exists. Please try again or enter a diffrent username."<<endl;
            break;
        }
        else if(emailcheck==email)
        {
            cout<<"Email already exists. Please try again or enter a diffrent email."<<endl;
            break;
        }
    }
    complete=true;
    filecheck.close();
}
    
    file << username << "," << hasher(password) << "," << email << endl;
    file.close();
}


//this is the login function for student
    string studentLogin()
        {
    ifstream file("StudentUser.txt", ios::in);
    string username, password, email, line;
    string usernamecheck,emailcheck,passwordcheck;
    bool isRegistered = false;
    string loggeduser="";
    while (isRegistered == false)
    {
        cout<<"Login Menu"<<endl;
        cout<<" Choose login with username or email"<<endl;
        string choice;
        cin>>choice;
        if(choice=="email")
        {
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;
            while (getline(file, line))
            {
                stringstream ss(line);
                getline(ss, usernamecheck, ',');
                getline(ss, passwordcheck, ',');
                getline(ss, emailcheck, ',');
                if(emailcheck==email && passwordcheck==hasher(password))
                {
                    isRegistered = true;
                    cout << "Login successful!" << endl;
                    loggeduser=username;
                    break;
                }

            }

        }

        else if(choice=="username")
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            while(getline(file, line))
            {
                stringstream ss(line);
                getline(ss, usernamecheck, ',');
                getline(ss, passwordcheck, ',');
                getline(ss, emailcheck, ',');
                if(usernamecheck==username && passwordcheck==hasher(password))
                {
                    isRegistered = true;
                    cout << "Login successful!" << endl;
                    loggeduser=username;
                    break;
                }

            }
        }
        else
        {
            cout<<"Invalid choice"<<endl;
            continue;
        }
        file.clear();
        file.seekg(0, ios::beg);
        if (isRegistered == false)
        {
            cout << "Invalid credentials. Please try again." << endl;
        }
    }
    file.close();
    return loggeduser;
    }
};

class Teacher:public user{
    private:
    string username,password,email;
    public:
    Teacher()
    {}
    void teacherSignup()
{
    fstream file("TeacherUser.txt", ios::app | ios::out);
    bool validEmail = false;

    cout << "Enter username: ";
    cin >> username;

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

    cout << "Enter password: ";
    cin >> password;
    while (password.length() < 6 || password.find(' ') != string::npos)
    {
        cout << "Password must be at least 6 characters long. Please try again." << endl;
        cout << "Enter password: ";
        cin >> password;
    }

    
    file << username << "," << password << "," << email << endl;
    file.close();
}

    void teacherLogin()
    {
    ifstream file("TeacherUser.txt", ios::in);
    string username, password, email, line;
    string usernamecheck,emailcheck,passwordcheck;
    bool isRegistered = false;
    string loggeduser="";
    while (isRegistered == false)
    {
        cout<<"Login Menu"<<endl;
        cout<<" Choose login with username or email"<<endl;
        string choice;
        cin>>choice;
        if(choice=="email")
        {
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;
            while (getline(file, line))
            {
                stringstream ss(line);
                getline(ss, usernamecheck, ',');
                getline(ss, passwordcheck, ',');
                getline(ss, emailcheck, ',');
                if(emailcheck==email && passwordcheck==password)
                {
                    isRegistered = true;
                    loggeduser=username;
                    cout << "Login successful!" << endl;
                    break;
                }

            }

        }

        else if(choice=="username")
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            while(getline(file, line))
            {
                stringstream ss(line);
                getline(ss, usernamecheck, ',');
                getline(ss, passwordcheck, ',');
                getline(ss, emailcheck, ',');
                if(usernamecheck==username && passwordcheck==password)
                {
                    isRegistered = true;
                    loggeduser=username;
                    cout << "Login successful!" << endl;
                    break;
                }

            }
        }
        else
        {
            cout<<"Invalid choice"<<endl;
            continue;
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
};



int main()
{
Student student;
// student.studentSignup();
// student.studentLogin();
// Teacher teacher;
// teacher.teacherSignup();
// teacher.teacherLogin();
}







//log-

/*
2.11.2025
created hashed password
created user class and added username,password,email as protected members
fixed studnet signup and login to use hashed password

*/