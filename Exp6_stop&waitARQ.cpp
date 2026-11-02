#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n, frame = 0;
    int choice;

    srand(time(0));

    cout << "Enter total number of frames: ";
    cin >> n;

    cout << "\n--- Stop and Wait ARQ Protocol ---\n";

    while (frame < n)
    {
        cout << "\nSender: Sending Frame " << frame << endl;

        
        int frameLost = rand() % 3;

        if (frameLost == 0)
        {
            cout << "Frame " << frame << " is LOST!" << endl;
            cout << "Timeout occurred..." << endl;
            cout << "Sender: Retransmitting Frame " << frame << endl;

            cout << "Receiver: Frame " << frame << " received" << endl;
            cout << "Receiver: Sending ACK " << frame << endl;
            cout << "Sender: ACK " << frame << " received" << endl;
        }
        else
        {
            cout << "Receiver: Frame " << frame << " received" << endl;

            
            int ackLost = rand() % 3;

            if (ackLost == 0)
            {
                cout << "ACK " << frame << " is LOST!" << endl;
                cout << "Timeout occurred..." << endl;
                cout << "Sender: Retransmitting Frame " << frame << endl;

                cout << "Receiver: Duplicate Frame " << frame
                     << " received" << endl;
                cout << "Receiver: Discarding duplicate frame" << endl;
                cout << "Receiver: Sending ACK " << frame << endl;
                cout << "Sender: ACK " << frame << " received" << endl;
            }
            else
            {
                cout << "Receiver: Sending ACK " << frame << endl;
                cout << "Sender: ACK " << frame << " received" << endl;
            }
        }

        frame++;
    }

    cout << "\nAll " << n << " frames transmitted successfully." << endl;
    cout << "Stop and Wait ARQ completed." << endl;

    return 0;
}
