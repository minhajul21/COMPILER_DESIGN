#include <iostream>
#include <vector>
#include <cctype>
using namespace std;


bool isNumberValue(const string &text) {
    if (text.empty()) return false;
    for (char c : text) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Task 2
bool checkOperator(char symbol) {
    string operators = "+-*/%=";
    for (char op : operators) {
        if (symbol == op)
            return true;
    }
    return false;
}

// Task 3
bool detectComment(const string &line) {
    bool singleLine = false;
    bool multiLine = false;
    int start = 0, end = 0;

    for (int i = 0; i < line.size() - 1; i++) {
        if (line[i] == '/' && line[i + 1] == '/') {
            singleLine = true;
            start = i + 2;
            break;
        }
        else if (line[i] == '/' && line[i + 1] == '*') {
            start = i + 2;
            for (int j = i + 2; j < line.size() - 1; j++) {
                if (line[j] == '*' && line[j + 1] == '/') {
                    multiLine = true;
                    end = j - 1;
                    break;
                }
            }
            break;
        }
    }

    if (singleLine) {
        cout << "→ Single line comment found.\n";
        cout << "Comment: " << line.substr(start) << endl;
        return true;
    }
    else if (multiLine) {
        cout << "→ Multi-line comment found.\n";
        cout << "Comment: " << line.substr(start, end - start + 1) << endl;
        return true;
    }
    else {
        cout << "→ No comment found.\n";
        return false;
    }
}

// Task 4
bool isValidStart(char c) {
    return (isalpha(c) || c == '_');
}

bool isValidChar(char c) {
    return (isalnum(c) || c == '_');
}

bool checkIdentifier(const string &text) {
    if (text.empty()) return false;
    if (!isValidStart(text[0])) return false;

    for (int i = 1; i < text.size(); i++) {
        if (!isValidChar(text[i])) return false;
    }
    return true;
}

// Task 5
double computeAverage() {
    int count;
    cout << "Enter how many numbers: ";
    cin >> count;

    vector<int> nums(count);
    int total = 0;

    cout << "Enter " << count << " numbers:\n";
    for (int i = 0; i < count; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    return static_cast<double>(total) / count;
}

// Task 6
void displayMinMax() {
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int minVal = arr[0], maxVal = arr[0];
    for (int num : arr) {
        if (num < minVal) minVal = num;
        if (num > maxVal) maxVal = num;
    }

    cout << "Minimum = " << minVal << endl;
    cout << "Maximum = " << maxVal << endl;
}

int main() {
    cout << "1. Check Numeric\n";
    cout << "2. Check Operator\n";
    cout << "3. Detect Comment Line\n";
    cout << "4. Validate Identifier\n";
    cout << "5. Find Average\n";
    cout << "6. Find Min & Max\n";
    cout << "7. Concatenate Name\n";
    cout << "0. Exit\n";
    cout << "==========\n";

    while (true) {
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        if (option == 0) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        switch (option) {
            case 1: {
                string text;
                cout << "Enter input: ";
                cin >> text;
                cout << (isNumberValue(text) ? " Numeric Constant\n" : "Not Numeric\n");
                break;
            }
            case 2: {
                char op;
                cout << "Enter symbol: ";
                cin >> op;
                cout << (checkOperator(op) ? "Valid Operator\n" : " Not an Operator\n");
                break;
            }
            case 3: {
                cin.ignore();
                string line;
                cout << "Enter line: ";
                getline(cin, line);
                detectComment(line);
                break;
            }
            case 4: {
                string word;
                cout << "Enter word: ";
                cin >> word;
                cout << (checkIdentifier(word) ? "Valid Identifier\n" : " Invalid Identifier\n");
                break;
            }
            case 5: {
                double avg = computeAverage();
                cout << "Average = " << avg << endl;
                break;
            }
            case 6:
                displayMinMax();
                break;
            case 7: {
                string first, last;
                cout << "Enter first name: ";
                cin >> first;
                cout << "Enter last name: ";
                cin >> last;
                cout << "Full name: " << first + " " + last << endl;
                break;
            }
            default:
                cout << "Invalid choice! Try again.\n";
        }
        cout << "-------------------------\n";
    }

    return 0;
}




