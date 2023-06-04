#include <iostream>

using namespace std;

int main()
{
    int n, digit, num, rev = 0;

    cin >> n;
    num = n;
    do {
        digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10;
    } while (num != 0);

    cout << rev << endl;
    if (rev == n)
        cout << "palindrome" << endl;
    else
        cout << "Non-palindrome" << endl;
    
    return 0;
}