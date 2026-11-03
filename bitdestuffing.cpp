#include <iostream>
using namespace std;

int main()
{
    int frame1[20], frame2[40], frame3[40], i, j = 0, k = 0, n, count = 0;

    cout << "Enter the size of frame: ";
    cin >> n;

    cout << "Enter the bits of frame: ";
    for (i = 0; i < n; i++)
    {
        cin >> frame1[i];
    }

    for (i = 0; i < n; i++)
    {
        frame2[j++] = frame1[i];
        if (frame1[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 5)
        {
            frame2[j++] = 0;
            count = 0;
        }
    }

    cout << "Bit-stuffed frame: ";
    for (i = 0; i < j; i++)
    {
        cout << frame2[i] << " ";
    }
    cout << endl;

    count = 0;
    for (i = 0; i < j; i++)
    {
        if (count == 5 && frame2[i] == 0)
        {
            count = 0;
            continue;
        }

        frame3[k++] = frame2[i];
        if (frame2[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }

    cout << "Destuffed frame: ";
    for (i = 0; i < k; i++)
    {
        
    }
    cout << endl;

    return 0;
}