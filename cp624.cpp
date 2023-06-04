#include <iostream>
using namespace std;

double add(double num1, double num2, double num3);
double avg(double sum, int n);

int main()
{
    double arr[3];
    double num, sum, average;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter a number: ";
        cin >> num;
        arr[i] = num;
    }

    sum = add(arr[0], arr[1], arr[2]);
    average = avg(sum, 3);
    cout << "Sum = " << sum << endl;
    cout << "Average : " << average << endl;
    
    return 0;
}

double add(double num1, double num2, double num3)
{
    return num1 + num2 + num3;
}

double avg(double sum, int n)
{
    return (sum / n);
}