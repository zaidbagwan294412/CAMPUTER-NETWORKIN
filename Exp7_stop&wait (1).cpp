#include <iostream>
using namespace std;

int main() {
    int totalFrames;

    cout << "Enter the number of frames to receive: ";
    cin >> totalFrames;

    for (int frame = 1; frame <= totalFrames; frame++) {

        int received;

        cout << "\nReceiver: Waiting for Frame " << frame << "..." << endl;

        cout << "Enter 1 if Frame " << frame
             << " is received correctly, otherwise 0: ";
        cin >> received;

        if (received == 1) {
            cout << "Receiver: Frame " << frame
                 << " received successfully." << endl;

            cout << "Receiver: Sending ACK for Frame "
                 << frame << "." << endl;
        }
        else {
            cout << "Receiver: Frame " << frame
                 << " is lost or corrupted." << endl;

            cout << "Receiver: No ACK sent." << endl;

            frame--;  
        }
    }

    cout << "\nReceiver: All frames received successfully." << endl;

    return 0;
}
