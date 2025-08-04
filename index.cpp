#include<bits/stdc++.h>

using namespace std;

class temp{
    string userName,Email,Password;
    string SearchName,SearchPass,SearchEmail;

    fstream file;
    public:
    void login();
    void signUp();
    void forget();

}obj;

int main(){
    char choice;

    cout<<"\n-1 Login";
    cout<<"\n-2 Sign Up";
    cout<<"\n-3 Forget Password";
    cout<<"\n-4 Exit";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    cin.ignore();

    switch (choice)
    {
    case '1':
        obj.login();
        break;
    
    case '2':
        obj.signUp();
        break;

    case '3':
        obj.forget();
        break;
    
    case '4':
        return 0;
        break;
    
    default:
        cout<<"Invalid expression";
    }


    return 0;
}

void temp :: signUp(){
    cout<<"\nEnter your UserName : ";
    getline(cin,userName);
    cout<<"Enter your Email : ";
    getline(cin,Email);
    cout<<"Enter your Password : ";
    getline(cin,Password);

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}

void temp :: login(){
    
    cout<<"Enter your UserName : ";
    getline(cin,SearchName);
    cout<<"\nEnter your Password : ";
    getline(cin,SearchPass);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');

    while(!file.eof()){
        if(userName == SearchName){
            if(Password == SearchPass){
                cout<<"\nAccount Login Successful";
                cout<<"\nUsername : "<<userName<<endl;
            }
            else{
                cout<<"Password is Incorrect";
            }
        }
        else{
                cout<<"Incorrect Username";
            }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');
    }
    file.close();
}

void temp :: forget(){

    cout<<"\nEnter your Username : ";
    getline(cin,SearchName);
    cout<<"\nEnter your Email Address : ";
    getline(cin,SearchEmail);

    file.open("loginData.txt", ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,Password,'\n');

    while(!file.eof()){
        if(userName == SearchName){
            if(Email == SearchEmail){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password : "<<Password<<endl;
            }
            else{
             cout<<"Email Not Found....!\n";   
            }
        }
        else{
            cout<<"UserName Not Found...!\n";
        }
    }
    file.close();
}