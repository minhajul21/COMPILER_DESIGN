#include <iostream>
#include <string>
using namespace std;

enum State { A, B, C, D, E, F, PHI };

int main() {
    string input;
    State current = A;   

    cout << "Enter the input string: ";
    cin >> input;

    for (char ch : input) {
        switch (current) {
            case A:
                current = (ch == 'a') ? B : (ch == 'b') ? C : PHI;
                break;
            case B:
                current = (ch == 'a') ? D : (ch == 'b') ? E : PHI;
                break;
            case C:
                current = (ch == 'a') ? B : PHI;
                break;
            case D:
                current = (ch == 'a') ? F : PHI;
                break;
            case E:
                current = (ch == 'b') ? F : PHI;
                break;
            case F:
                current = F;
                break;
            case PHI:
                current = PHI;
                break;
        }
    }

    if (current == F) {
        cout << "String ACCEPTED by DFA" << endl;
    } else {
        cout << "String REJECTED by DFA" << endl;
    }

    return 0;
}
