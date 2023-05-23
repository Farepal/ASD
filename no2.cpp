#include <iostream>
using namespace std;

int main()
{
    int jumlahTeman;
    cin >> jumlahTeman;
    int arr[jumlahTeman];
    for (int i = 0; i < jumlahTeman; i++)
    {
        int t;
        cout << "Masukkan Tagihan orang ke-" << i+1 << " : ";
        cin >> t;
        arr[i] = t;
    }
    cout << "Masukkan n diskon" << " : ";
    int n;
    cin >> n;
    for (int i = 0; i < jumlahTeman; i++)
        arr[i] = arr[i] - (arr[i] / 100);
    
    for (int i = 0; i < jumlahTeman; i++)
        cout << "Tagihan orang ke-" << i << " : " << arr[i] << endl;
    
    return 0;
}