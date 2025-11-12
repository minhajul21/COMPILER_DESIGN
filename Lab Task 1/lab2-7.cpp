#include <iostream>
using namespace std;

string concatenateName(const string &firstName, const string &lastName) {
    return firstName + " " + lastName;
}

int main() {
    string firstName, lastName;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    string fullName = concatenateName(firstName, lastName);
    cout << "Full name: " << fullName << endl;

    return 0;
}

