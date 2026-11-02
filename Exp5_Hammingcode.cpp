#include <iostream>
using namespace std;

int main() {
    int d[7];
    int p1, p2, p4;
    int error;

    cout << "Enter 7-bit Hamming code: ";

    for (int i = 0; i < 7; i++) {
        cin >> d[i];
    }

    
    cout << "\nReceived Hamming Code: ";
    for (int i = 0; i < 7; i++) {
        cout << d[i];
    }


    p1 = d[0] ^ d[2] ^ d[4] ^ d[6];


    p2 = d[1] ^ d[2] ^ d[5] ^ d[6];

    
    p4 = d[3] ^ d[4] ^ d[5] ^ d[6];


    error = p1 * 1 + p2 * 2 + p4 * 4;

    cout << "\n\nP1 = " << p1;
    cout << "\nP2 = " << p2;
    cout << "\nP4 = " << p4;

    if (error == 0) {
        cout << "\n\nNo error detected.";
    }
    else {
        cout << "\n\nError detected at position: " << error;

        
        d[error - 1] = d[error - 1] ^ 1;

        cout << "\nCorrected Hamming Code: ";

        for (int i = 0; i < 7; i++) {
            cout << d[i];
        }
    }

    cout << "\n\nOriginal Data Bits: ";
    cout << d[2] << d[4] << d[5] << d[6];

    cout << endl;

    return 0;
}
