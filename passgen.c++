#include <iostream>
#include <string>
#include <random>

using namespace std;

string generatePassword(int length, bool useUpper, bool useLower, bool useDigits, bool useSymbols) {
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()-_=+<>?";

    string charset = "";

    if (useUpper) charset += upper;
    if (useLower) charset += lower;
    if (useDigits) charset += digits;
    if (useSymbols) charset += symbols;

    if (charset.empty()) {
        return "Error: No character set selected!";
    }

    // Random generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, charset.size() - 1);

    string password = "";
    for (int i = 0; i < length; i++) {
        password += charset[dist(gen)];
    }

    return password;
}

int main() {
    int length;
    char choice;
    bool useUpper = false, useLower = false, useDigits = false, useSymbols = false;

    cout << "Enter password length: ";
    cin >> length;

    cout << "Include uppercase letters? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') useUpper = true;

    cout << "Include lowercase letters? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') useLower = true;

    cout << "Include digits? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') useDigits = true;

    cout << "Include symbols? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') useSymbols = true;

    string password = generatePassword(length, useUpper, useLower, useDigits, useSymbols);

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}
