#include <bits/stdc++.h>
using namespace std;

class Temp {
    string userName, Email, Password;
    string SearchName, SearchPass, SearchEmail;
    fstream file;

public:
    void login();
    void signUp();
    void forget();
} obj;

void clearScreen() {
    cout << "\n-------------------------\n";
}

int main() {
    char choice;
    while (true) {
        clearScreen();
        cout << "\n1. Login";
        cout << "\n2. Sign Up";
        cout << "\n3. Forget Password";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
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
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

void Temp::signUp() {
    clearScreen();
    cout << "=== Sign Up ===\n";
    cout << "Enter Username: ";
    getline(cin, userName);
    cout << "Enter Email: ";
    getline(cin, Email);
    cout << "Enter Password: ";
    getline(cin, Password);

    // Save to file
    file.open("loginData.txt", ios::app);
    if (file.is_open()) {
        file << userName << "*" << Email << "*" << Password << endl;
        file.close();
        cout << "\nAccount created successfully.\n";
    } else {
        cout << "\nFailed to open file.\n";
    }
}

void Temp::login() {
    clearScreen();
    cout << "=== Login ===\n";
    cout << "Enter Username: ";
    getline(cin, SearchName);
    cout << "Enter Password: ";
    getline(cin, SearchPass);

    bool found = false;

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "No users registered yet.\n";
        return;
    }

    while (getline(file, userName, '*') &&
           getline(file, Email, '*') &&
           getline(file, Password)) {
        if (userName == SearchName) {
            found = true;
            if (Password == SearchPass) {
                cout << "\nLogin successful! Welcome, " << userName << ".\n";
            } else {
                cout << "Incorrect password.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Username not found.\n";
    }

    file.close();
}

void Temp::forget() {
    clearScreen();
    cout << "=== Forgot Password ===\n";
    cout << "Enter Username: ";
    getline(cin, SearchName);
    cout << "Enter Email: ";
    getline(cin, SearchEmail);

    bool found = false;

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "No users registered yet.\n";
        return;
    }

    while (getline(file, userName, '*') &&
           getline(file, Email, '*') &&
           getline(file, Password)) {
        if (userName == SearchName) {
            found = true;
            if (Email == SearchEmail) {
                cout << "\nAccount found.\nYour password is: " << Password << endl;
            } else {
                cout << "Email does not match our records.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Username not found.\n";
    }

    file.close();
}
