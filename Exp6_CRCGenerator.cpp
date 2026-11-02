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

    int dataLength = data.length();
    int generatorLength = generator.length();

    temp = data;
    for (int i = 0; i < generatorLength - 1; i++)
    {
        temp += '0';
    }

    
    for (int i = 0; i <= temp.length() - generatorLength; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generatorLength; j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    string crc = temp.substr(dataLength, generatorLength - 1);

  
    string codeword = data + crc;

    cout << "\nCRC = " << crc << endl;
    cout << "Transmitted Codeword = " << codeword << endl;

    return 0;
}
