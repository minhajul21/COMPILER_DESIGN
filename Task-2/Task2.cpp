#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void isIdentifier(string input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            cout << "→ \"" << input << "\" is NOT a valid identifier (contains space)" << endl;
            return;
        }
    }

    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
           input[0] == '_')) {
        cout << " \"" << input << "\" is NOT a valid identifier (invalid first character)" << endl;
        return;
    }

    for (int i = 1; input[i] != '\0'; i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
               input[i] == '_')) {
            cout << "→ \"" << input << "\" is NOT a valid identifier (invalid character)" << endl;
            return;
        }
    }

    cout << "→ \"" << input << "\" is a VALID identifier " << endl;
}

int main()
{
    string filename;

    cout << "Enter the text file name (e.g., sample.txt): ";
    cin >> filename;

    ifstream file(filename);
    string input;

    if (!file) {
        cout << "Error: Unable to open file \"" << filename << "\". Please check the file name and try again." << endl;
        return 0;
    }

    cout << "\nChecking identifiers from \"" << filename << "\"...\n" << endl;

    while (getline(file, input)) {
        if (input.empty()) continue;
        cout << "Checking: \"" << input << "\"" << endl;
        isIdentifier(input);
        cout << endl;
    }

    file.close();
    cout << "Checking completed successfully!" << endl;
    return 0;
}
