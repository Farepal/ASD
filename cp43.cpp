#include <iostream>
using namespace std;

struct tigaFilm {
    struct film_a 
    {
        char judul_film[30];
        int tahun_terbit;
        char rating[6];
        char sutradara[20];
        int durasi;
    } a;
    struct film_b
    {
        char judul_film[30];
        int tahun_terbit;
        char genre[200];
        char pemeran_utama[20];
        int durasi;
    } b;
    struct film_c
    {
        char judul_film[30];
        int tahun_terbit;
        char sinopsis[100];
        char negara_produksi[25];
        int durasi;
    } c;
};

int main()
{
    tigaFilm film;

    cout << "Judul film pertama : "; 
    cin.get(film.a.judul_film, 30);
    cin.ignore();
    cout << "Tahun produksi film : ";
    cin >> film.a.tahun_terbit;
    cin.ignore();
    cout << "Rating film : ";
    cin.get(film.a.rating, 6);
    cin.ignore();
    cout << "Sutradara : ";
    cin.get(film.a.sutradara, 20);
    cin.ignore();
    cout << "Durasi film : ";
    cin >> film.a.durasi;
    cin.ignore();

    cout << "\nJudul film Kedua : "; 
    cin.get(film.b.judul_film, 30);
    cin.ignore();
    cout << "Tahun produksi film : ";
    cin >> film.b.tahun_terbit;
    cin.ignore();
    cout << "Genre film : ";
    cin.get(film.b.genre, 200);
    cin.ignore();
    cout << "Pemeran Utama : ";
    cin.get(film.b.pemeran_utama, 20);
    cin.ignore();
    cout << "Durasi film : ";
    cin >> film.b.durasi;
    cin.ignore();

    cout << "\nJudul film Ketiga : "; 
    cin.get(film.c.judul_film, 30);
    cin.ignore();
    cout << "Tahun produksi film : ";
    cin >> film.c.tahun_terbit;
    cin.ignore();
    cout << "Sinopsis film : ";
    cin.get(film.c.sinopsis, 100);
    cin.ignore();
    cout << "Negara Produksi : ";
    cin.get(film.c.negara_produksi, 25);
    cin.ignore();
    cout << "Durasi film : ";
    cin >> film.c.durasi;
    cin.ignore();

    cout << endl;
    cout << "FILM PERTAMA" << endl;
    cout << "Judul Film   : " << film.a.judul_film << endl;
    cout << "Tahun terbit : " << film.a.tahun_terbit << endl;
    cout << "Rating Film  : " << film.a.rating << endl;
    cout << "Sutradara    : " << film.a.sutradara << endl;
    cout << "Durasi Film  : " << film.a.durasi << endl;

    cout << "FILM KEDUA" << endl;
    cout << "Judul Film   : " << film.b.judul_film << endl;
    cout << "Tahun terbit : " << film.b.tahun_terbit << endl;
    cout << "Genre Film   : " << film.b.genre << endl;
    cout << "Pemeran Utama: " << film.b.pemeran_utama << endl;
    cout << "Durasi Film  : " << film.b.durasi << endl;

    cout << "FILM KETIGA" << endl;
    cout << "Judul Film   : " << film.c.judul_film << endl;
    cout << "Tahun terbit : " << film.c.tahun_terbit << endl;
    cout << "Sinopsis     : " << film.c.sinopsis << endl;
    cout << "Negara       : " << film.c.negara_produksi << endl;
    cout << "Durasi Film  : " << film.c.durasi << endl;

    cout << endl;
    cout << "Ukuran byte dari elemen struct film_a: " << sizeof(film.a) << endl;
    cout << "Ukuran byte dari elemen struct film_b: " << sizeof(film.b) << endl;
    cout << "Ukuran byte dari elemen struct film_c: " << sizeof(film.c) << endl;

    cout << "Ukuran byte dari variabel union tigaFilm: " << sizeof(film) << endl;
}