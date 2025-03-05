#include <iostream>
#include <fstream>
#include <string>

void registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ofstream file(username + ".txt",std::ios::out);
    file << username << std::endl;
    file << password << std::endl;
    file.close();
    std::cout << "Registration successful!" << std::endl;
}

void loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream file(username + ".txt");
    std::string storedUsername, storedPassword;
    std::getline(file, storedUsername);
    std::getline(file, storedPassword);
    file.close();

    if (password == storedPassword) {
        std::cout << "Login successful!" << std::endl;
    } else {
        std::cout << "Incorrect password." << std::endl;
    }
}

int main() {
    int choice;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    }

    return 0;
}
