#include <iostream>
using namespace std;

union jenis_film {
    struct film_a 
    {
        char judul[30];
        int tahun_produksi;
        float rating;
        char sutradara[20];
        int durasi;
    } a;
    struct film_b
    {
        char judul[30];
        int tahun_produksi;
        char genre[20];
        char sutradara[20];
        int durasi;
    } b;
    struct film_c
    {
        char judul[30];
        int tahun_produksi;
        char sinopsis[100];
        char sutradara[20];
        int durasi;
    } c;
};

int main()
{
    union jenis_film film;

    cout << "Judul film pertama : "; 
    cin.get(film.a.judul, 30);
    cin.ignore();
    cout << "Tahun produksi film : ";
    cin >> film.a.tahun_produksi;
    cin.ignore();
    cout << "Rating film : ";
    cin >> film.a.rating;
    cin.ignore();
    cout << "Sutradara : ";
    cin.get(film.a.sutradara, 20);
    cin.ignore();
    cout << "Durasi film : ";
    cin >> film.a.durasi;
    cin.ignore();

    cout << "\nJudul film Kedua : "; 
    cin.get(film.b.judul, 30);
    cin.ignore();
    cout << "Tahun produksi film : ";
    cin >> film.b.tahun_produksi;
    cin.ignore();
    cout << "Genre film : ";
    cin.get(film.b.genre, 20);
    cin.ignore();
    cout << "Sutradara : ";
    cin.get(film.b.sutradara, 20);
    cin.ignore();
    cout << "Durasi film : ";
    cin >> film.b.durasi;
    cin.ignore();

    cout << "\nJudul film Ketiga : "; 
    cin.get(film.c.judul, 30);
    cin.ignore();
    cout << "Tahun produksi film : ";
    cin >> film.c.tahun_produksi;
    cin.ignore();
    cout << "Sinopsis film : ";
    cin.get(film.c.sinopsis, 100);
    cin.ignore();
    cout << "Sutradara : ";
    cin.get(film.c.sutradara, 20);
    cin.ignore();
    cout << "Durasi film : ";
    cin >> film.c.durasi;
    cin.ignore();

    cout << "Ukuran byte dari elemen struct film_a: " << sizeof(film.a) << endl;
    cout << "Ukuran byte dari elemen struct film_b: " << sizeof(film.b) << endl;
    cout << "Ukuran byte dari elemen struct film_c: " << sizeof(film.c) << endl;

    cout << "Ukuran byte dari variabel union jenis_film: " << sizeof(film) << endl;
}