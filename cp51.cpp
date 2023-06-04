#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s1[10], s2[20], s3[20], s4[30], i;
    cout << "Masukkan string pertama untuk ditemukan panjang string tersebut :";
    cin.get(s1, 10);
    // getline(cin, s1);
    cout << "\nString yang dimasukkan : " << s1;

    cout << "\nPanjang String tersebut adalah : " << strlen(s1);
    cout << "\nMasukkan string kedua untuk ditemukan panjang string tersebut :";
    cin >> s2;
    cout << "\nString yang dimasukkan : " << s2;

    cout << "\nPanjang String tersebut adalah : " << strlen(s2);

    strcpy(s3, s2);
    cout << "\nSalin string kedua dalam string ketiga ";
    cout << "\nString ketiga adalah : " << s3;

    cout << "\nSambungkan string pertama dan kedua:";
    strcpy(s4, s1);
    strcat(s4, s2);
    cout << "\nHasil penyambungan string pertama dan kedua adalah : " << s4 << endl;
    cout << endl << "\nBandingkan string pertama dan kedua :";
    
    i = strcmp(s1, s2);
    if (i == 0)
        cout << "\nBoth strings are equal\n";
    else if (i < 0)
        cout << s1 << " is less than " << s2 << endl;
    else 
        cout << s1 << " is greater than " << s2;

    cout << endl << "\nBandingkan string kedua dan ketiga :";

    i = strcmp(s2, s3);
    if (i == 0)
        cout << "\nBoth strings are equal\n";
    else if (i < 0)
        cout << s2 << " is less than " << s3 << endl;
    else cout << s2 << " is greater than " << s3;
    return 0;
}