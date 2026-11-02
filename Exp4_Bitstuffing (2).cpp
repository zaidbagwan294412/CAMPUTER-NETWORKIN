#include <iostream>
using namespace std;

int main() {
    string data, destuffed = "";
    int count = 0;

    cout << "Enter received data: ";
    cin >> data;


    for (char bit : data) {
        destuffed += bit;

        if (bit == '1')
            count++;
        else
            count = 0;

      
        if (count == 5) {
            count = 0;
        }
    }

    cout << "\nReceived Data: " << data;
    cout << "\nAfter Bit De-stuffing: " << destuffed << endl;

    return 0;
}
