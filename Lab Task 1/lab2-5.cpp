#include <iostream>
using namespace std;

int main() {
    int size;

    cout << "Enter number of elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }

    int numbers[size];
    int sum = 0;

    cout << "Enter " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    float average = static_cast<float>(sum) / size;

    cout << "\n------------------\n";
    cout << "Total Sum   = " << sum << endl;
    cout << "Total Count = " << size << endl;
    cout << "Average     = " << average << endl;
    cout << "-------------------\n";

    return 0;
}


