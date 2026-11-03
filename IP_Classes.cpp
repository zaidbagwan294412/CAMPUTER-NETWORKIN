#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    char classType;
    char dot;

    cout << "Enter IP address (a.b.c.d): ";
    cin >> a >> dot >> b >> dot >> c >> dot >> d;

    if (a >= 0 && a <= 127) {
        classType = 'A';
    }
    else if (a >= 128 && a <= 191) {
        classType = 'B';
    }
    else if (a >= 192 && a <= 223) {
        classType = 'C';
    }
    else if (a >= 224 && a <= 239) {
        classType = 'D';
    }
    else if (a >= 240 && a <= 255) {
        classType = 'E';
    }
    else {
        cout << "Invalid IP address" << endl;
        return 0;
    }

    cout << "\nIP Address        : " << a << "." << b << "." << c << "." << d << endl;
    cout << "Class of Address  : " << classType << endl;

    if (classType == 'A') {
        cout << "Network Mask      : 255.0.0.0" << endl;
        cout << "No. of Addresses  : 16777216" << endl;   
        cout << "First Address     : " << a << ".0.0.0" << endl;
        cout << "Last Address      : " << a << ".255.255.255" << endl;
    }
    else if (classType == 'B') {
        cout << "Network Mask      : 255.255.0.0" << endl;
        cout << "No. of Addresses  : 65536" << endl;      
        cout << "First Address     : " << a << "." << b << ".0.0" << endl;
        cout << "Last Address      : " << a << "." << b << ".255.255" << endl;
    }
    else if (classType == 'C') {
        cout << "Network Mask      : 255.255.255.0" << endl;
        cout << "No. of Addresses  : 256" << endl;       
        cout << "First Address     : " << a << "." << b << "." << c << ".0" << endl;
        cout << "Last Address      : " << a << "." << b << "." << c << ".255" << endl;
    }
    else if (classType == 'D') {
        cout << "Reserved for      : Multicast" << endl;
        cout << "Range             : 224.0.0.0 - 239.255.255.255" << endl;
    }
    else if (classType == 'E') {
        cout << "Reserved for      : Future use" << endl;
        cout << "Range             : 240.0.0.0 - 255.255.255.255" << endl;
    }

    return 0;
}