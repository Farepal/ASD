#include <iostream>
#include <string>

using namespace std;

float inp();
void luasVol(float);
void printhasil(float, float, float);

int main()
{
    float d = inp();
    luasVol(d);
    return 0;
}

float inp()
{
    float d;
    cout << "Masukkan nilai diameter dari bola: ";
    cin >> d;
    return d;
}

void luasVol(float d)
{
    float pi = 3.1416;
    float luas = float(pi*d*d), volume = float(pi*d*d*d) / 6;
    printhasil(luas, volume, d);
}

void printhasil(float area, float vol, float d)
{
    cout << "Diameter Bola " << d << endl;
    cout << "Luas Permukaan Bola " << area << endl;
    cout << "Volume Bola " << vol << endl;
}