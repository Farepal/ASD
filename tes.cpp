#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x, n = 0;
    cin >> x;
    for (; x > 0; x /= 10)
        n = n*10 + (x%10);
    cout << n << endl;
}