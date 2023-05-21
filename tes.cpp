#include <iostream>
using namespace std;

int main()
{
    int x = 0;
    if (++x && 1)
        cout << "YES" << endl;
    cout << x << endl;
}