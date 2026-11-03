#include <iostream>
#include <string>

using namespace std;

int main() {
    string data, divisor;

    cout << "Enter data bits: ";
    cin >> data;

    cout << "Enter divisor: ";
    cin >> divisor;

    int zeros = divisor.length() - 1;
    string code = data;

    for (int i = 0; i < zeros; i++) {
        code += '0';
    }

    for (int i = 0; i <= (int)code.length() - (int)divisor.length(); i++) {
        if (code[i] == '1') {
            for (int j = 0; j < (int)divisor.length(); j++) {
                if (code[i + j] == divisor[j]) {
                    code[i + j] = '0';
                } else {
                    code[i + j] = '1';
                }
            }
        }
    }

    string remainder = code.substr(code.length() - zeros);
    string transmittedData = data + remainder;

    cout << "\n--- Sender Side ---" << endl;
    cout << "CRC remainder: " << remainder << endl;
    cout << "Transmitted data: " << transmittedData << endl;

    return 0;
}
