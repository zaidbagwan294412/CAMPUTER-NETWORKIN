#include <iostream>
using namespace std;

int main() {
    int totalFrames;

    cout << "Enter the number of frames to send: ";
    cin >> totalFrames;

    for (int frame = 1; frame <= totalFrames; frame++) {

        bool acknowledged = false;

        while (!acknowledged) {

            cout << "\nSender: Sending Frame " << frame << "..." << endl;

            int ack;
            cout << "Enter ACK received (1 = ACK received, 0 = Timeout): ";
            cin >> ack;

            if (ack == 1) {
                cout << "Sender: ACK received for Frame "
                     << frame << "." << endl;

                acknowledged = true;
            }
            else {
                cout << "Sender: Timeout occurred!" << endl;
                cout << "Sender: Retransmitting Frame "
                     << frame << "..." << endl;
            }
        }
    }

    cout << "\nAll frames have been successfully transmitted." << endl;

    return 0;
}
