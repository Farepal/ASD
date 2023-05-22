#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
                cout <<  << "\t";
            else
                cout << 0 << "\t";
        }
        cout << endl;
    }

    string s;
    cin >> s;
    int indX = s.find("x");
    

    // int i = 0, j = 0;
    // do {
    //     do {
    //         cout << rand() << "\t";

    //     } while (j < 3)
    //     cout << endl;
    //     i++;
    // } while (i < 3)
}