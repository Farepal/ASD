#include <iostream>
using namespace std;

int main()
{
    int input, sum = 0;
    cout << "Masukkan angka : ";
    cin >> input;
    for (; input > 0; input/=10)
        sum += (input%10);
    if (sum%9==0)
        cout << "Bisa dibagi 9"<< endl;
    else
        cout << "Tidak bisa dibagi 9" << endl;
}