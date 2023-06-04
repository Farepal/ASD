#include <iostream>
using namespace std;
struct
{
    int roll, age;
    string name;
} vr[4];

int main()
{
    int i, j, k, max;
    string temp;

    for (i = 0; i < 4; i++)
    {
        cout << "Enter " << i + 1 << " Student Record\n";
        cout << "Enter Roll no: " << endl;
        cin >> vr[i].roll;
        cin.ignore(256, '\n');
        cout << "Enter age : " << endl;
        cin >> vr[i].age;
        cin.ignore(256, '\n');
        cout << "Enter Name : " << endl;
        getline(cin, vr[i].name);
    }

    cout << endl;

    for (j = 0; j < 4; j++)
    {
        cout << "\nDisplay " << j + 1 << " Student Record";
        cout << "\nRoll no.: " << vr[j].roll;
        cout << "\nAge : " << vr[j].age;
        cout << "\nName : " << vr[j].name << endl;
    }

    max = vr[0].age;
    int flag;
    for (k = 1; k < 4; k++)
    {
        if (max < vr[k].age)
        {
            max = vr[k].age;
            flag = k;
        }
    }

    cout << "\nThe oldest age's student is : " << max << " years old";
    return 0;
}