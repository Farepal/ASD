#include <iostream>
#include <string>
#include <vector>

using namespace std;
void showDiagonal(vector<vector<int>> x)
{
    for (int i = 0;i  <x.size(); i++)
    {
        for (int j = 0; j <x[i].size(); j++)
        {
            if (i == j)
                cout << x[i][j] << " ";
            else    
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;a
}

void lower(vector<vector<int>> x)
{
    for (int i = 0;i  <x.size(); i++)
    {
        for (int j = 0; j <x[i].size(); j++)
        {
            if (i >= j)
                cout << x[i][j] << " ";
            else    
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void upper(vector<vector<int>> x)
{
    for (int i = 0;i  <x.size(); i++)
    {
        for (int j = 0; j <x[i].size(); j++)
        {
            if (i <= j)
                cout << x[i][j] << " ";
            else    
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int m,n;
    cin >> m >> n;

    vector<vector<int>> x;
    for (int i = 0;i  <m; i++)
    {
        vector <int> t(n);
        for (int j = 0; j <n; j++)
        {
            cin >> t[j];
        }
        x.push_back(t);
    }
    cout << endl;
    showDiagonal(x);
    lower(x);
    upper(x);
    return 0;
}