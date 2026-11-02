#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator, temp;

    cout << "Enter Data: ";
    cin >> data;

    cout << "Enter Generator: ";
    cin >> generator;


    temp = data;

    for (int i = 0; i < generator.length() - 1; i++)
    {
        temp = temp + "0";
    }


    for (int i = 0; i <= temp.length() - generator.length(); i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generator.length(); j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    string crc = temp.substr(
        data.length(),
        generator.length() - 1
    );

    cout << "\nCRC = " << crc << endl;
    cout << "Transmitted Data = " << data + crc << endl;

    return 0;
}
