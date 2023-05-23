#include <iostream>//file header
#include <algorithm>//file header
using namespace std;

struct BOOKS
{
    string bookName;
    string authorName;
    int year;
    long cost;
} book[5]/*array structure*/;
void getData();//function prototype
bool compareBooks(BOOKS a, BOOKS b);//function prototype
void showData();//user defined function

int main()
{
    cout << "=================MY FAVORITBE BOOKS==========" << endl;
    cout << "\n=> Enter your Five Favorite Books Detail: " << endl;
    //getData di sini termasuk function call
    getData();//user defined function

    //sort ini termasuk built in function
    //sort disini juga termasuk function call
    sort(book/*parameter aktual*/, book+5/*parameter aktual*/, compareBooks/*parameter aktual*/);
    //showData() di sini termasuk function call
    showData();
    return 0;
}

//function implementation yaitu getData()
void getData()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter name of Book #" << i << ":"<< endl;
        cin >> book[i].bookName;
        cout << "Enter Author Name: " << endl;
        cin >> book[i].authorName;
        cout << "Enter Published Year of Book: " << endl;
        cin >> book[i].year;
        cout <<"Enter cost of Book: " << endl;
        cin >> book[i].cost;
    }
}

//function implementation
void showData()
{
    for (int i = 0; i < 5; i++);
}

//function implementation
bool compareBooks(BOOKS a/*parameter formal*/, BOOKS b/*parameter formal*/)
{
    if (a.cost < b.cost)
        return true;
    return false;
}