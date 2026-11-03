#include <iostream>
using namespace std;

int main()
{
    int frame[5] ;
    int timeout;

    cout << "Enter frame value: ";
    cin >> timeout;

    for (int i = 0; i < 5; i++)
    {
        cout << "Frame sent: " << frame[i] << endl;
        

        int delay = rand() % 10;
        cin >> frame[i];
        if (timeout < delay)
        {
            cout << "Acknowledgment " << i << endl;
        }
        else
        {
            cout << "Waiting" << endl;
        }
    }
    return 0;
}
