#include <iostream>
using namespace std;

struct movies_t {
    string title;
    int year;
} films[5];

void memasukkanData()
{
    int n;
    cout << "\nEnter your 5 favourite movies: \n";
    for (n = 0; n < 5; n++)
    {
        cout << "Enter title : " << endl;
        cin >> films[n].title;
        cout << "Enter year : " << endl;
        cin >> films[n].year;
    }
}

void menampilkanData()
{
    int n;
    cout << "\nYou have entered these movies:\n";
    for (n = 0; n < 5; n++)
    {
        cout << n+1 << " " << films[n].title;
        cout << "(" << films[n].year << ")\n";
    }
}

int main()
{
    memasukkanData();
    menampilkanData();
    return 0;
}