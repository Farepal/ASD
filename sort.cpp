#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> x;
int countSwap = 0;
int countComparison = 0;
int anjing = 0;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    countSwap++;
}

void show()
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }
}

void BubbleSort()
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            countComparison++;
            if (x[j] > x[j + 1])
                swap(x[j], x[j + 1]);
        }
    }
}

void SelectionSort()
{
    for (int i = 0; i < n; i++)
    {
        int IndexTerbawah = i;
        for (int j = i + 1; j < n; j++)
        {
            if (x[j] < x[IndexTerbawah])
                IndexTerbawah = j;
        }
        swap(x[i], x[IndexTerbawah]);
    }
}

void InsertionSort()
{
    for (int i = 0; i < n; i++)
    {
        int pos = i;
        while (pos > 0 && x[pos] < x[pos - 1])
        {
            swap(x[pos], x[pos - 1]);
            pos--;
        }
    }
}

void Merge(int aleft, int aright, int bleft, int bright)
{
    vector<int> temp;
    int aIndex = aleft, bIndex = bleft;
    while (aIndex <= aright && bIndex <= bright)
    {
        if (x[aIndex] <= x[bIndex])
        {
            temp.push_back(x[aIndex]);
            aIndex++;
        }
        else
        {
            temp.push_back(x[bIndex]);
            bIndex++;
        }
    }

    while (aIndex <= aright)
    {
        temp.push_back(x[aIndex]);
        aIndex++;
    }
    while (bIndex <= bright)
    {
        temp.push_back(x[bIndex]);
        bIndex++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        x[aleft + i] = temp[i];
    }
}

void MergeSort(int left, int right)
{
    if (left != right)
    {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid, mid + 1, right);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        x.push_back(t);
    }
    // BubbleSort();
    // SelectionSort();
    // InsertionSort();
    MergeSort(0, n - 1);
    show();
    return 0;
}