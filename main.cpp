#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if a username already exists in the file
bool isUsernameTaken(string username) {
    ifstream file("database.txt");
    string u, p;
    
    while (file >> u >> p) {
        if (u == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Function for User Registration
void registerUser() {
    string username, password;
    
    cout << "\n------------------------------------" << endl;
    cout << "          USER REGISTRATION         " << endl;
    cout << "------------------------------------" << endl;
    
    cout << "Enter a new username: ";
    cin >> username;

    // Check if user already exists
    if (isUsernameTaken(username)) {
        cout << "Error: Username already exists! Please try another one." << endl;
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    // Save user credentials to database file using append mode
    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration successful! You can now log in." << endl;
}

// Function for User Login
void loginUser() {
    string username, password;
    string u, p;
    bool loginSuccess = false;

    cout << "\n------------------------------------" << endl;
    cout << "             USER LOGIN             " << endl;
    cout << "------------------------------------" << endl;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database.txt");

    // Search for matching credentials line by line in the file
    while (file >> u >> p) {
        if (u == username && p == password) {
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (loginSuccess) {
        cout << "\nLogin successful! Welcome, " << username << "!" << endl;
    } else {
        cout << "\nError: Invalid username or password!" << endl;
    }
}

// Main Menu Function
int main() {
    int choice;

    do {
        cout << "\n====================================" << endl;
        cout << "    LOGIN & REGISTRATION SYSTEM     " << endl;
        cout << "====================================" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "\nExiting system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please select 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
