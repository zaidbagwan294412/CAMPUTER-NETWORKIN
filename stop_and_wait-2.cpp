#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    int n = 5;
    if (argc > 1) n = atoi(argv[1]);
    if (n < 1) n = 5;

    srand(time(0));

    cout << "\nStop-and-Wait ARQ - Sending " << n << " frames\n";

    int seq = 0;
    for (int i = 0; i < n; ++i) {
        cout << "\n[SEND] Frame " << seq << " (data: Frame_" << i + 1 << ")\n";

        // Simulate packet loss (30% chance)
        if (rand() % 10 < 3) {
            cout << "  [DROP] Frame lost!\n";
            cout << "  [TIMEOUT] Retransmitting...\n";
            --i;  // Retry same frame
            continue;
        }
        cout << "  [RECV] Frame delivered\n";

        // Simulate ACK loss (20% chance)
        if (rand() % 10 < 2) {
            cout << "  [DROP] ACK lost!\n";
            cout << "  [TIMEOUT] Retransmitting...\n";
            --i;  // Retry same frame
            continue;
        }
        cout << "  [RECV] ACK " << seq << " received\n";

        seq = 1 - seq;  // Toggle sequence number
    }

    cout << "\nAll frames sent successfully!\n\n";
    return 0;
}
