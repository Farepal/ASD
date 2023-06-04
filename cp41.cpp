#include <iostream>
using namespace std;

struct Mahasiswa
{
    char nama[40];
    int angkatan;
};

int main()
{
    Mahasiswa mhs;
    cout<<"Masukkan Nama Mahasiswa :";
    cin.get(mhs.nama, 40);
    cout<<"Masukkan Angkatan :";
    cin>>mhs.angkatan;

    cout<<"Data Mahasiswa"<<endl;
    cout<<"Nama :"<<mhs.nama<<endl;
    cout<<"Angkatan :"<<mhs.angkatan<<endl;

    cout<<"Alokasi memori untuk elemen nama : " <<&mhs.nama<<endl;
    cout<<"Alokasi memori untuk elemen angkatan : "<<&mhs.angkatan<<endl;

    cout<<"Ukuran dari variabel union : " << sizeof(Mahasiswa) << endl;

    return 0;
}