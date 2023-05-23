#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;
    int sum, absDifference;

    cin >> a >> b;

    //masukkan kode di sini
    sum = *pa + *pb;
    absDifference = *pa - *pb;
    if (absDifference < 0)
        absDifference *= (-1);

    cout << sum << "\n" << absDifference;
    return 0;
}