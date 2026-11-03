#include <iostream>
#include <string>

using namespace std;

int main() {
    string receivedData, divisor;

    cout << "Enter received data: ";
    cin >> receivedData;

    cout << "Enter divisor/generator bits: ";
    cin >> divisor;

    for (int i = 0;
        i <= (int)receivedData.length() - (int)divisor.length();
        i++) {
        if (receivedData[i] == '1') {
            for (int j = 0; j < (int)divisor.length(); j++) {
                if (receivedData[i + j] == divisor[j]) {
                    receivedData[i + j] = '0';
                } else {
                    receivedData[i + j] = '1';
                }
            }
        }
    }

    bool error = false;


    for (int i = receivedData.length() - divisor.length() + 1;
        i < (int)receivedData.length();
        i++) {
        if (receivedData[i] == '1') {
            error = true;
        }
    }

    cout << "\n--- Receiver Side ---" << endl;

    if (error) {
        cout << "Error detected." << endl;
    } else {
        cout << "No error detected." << endl;
    }

    return 0;
}
