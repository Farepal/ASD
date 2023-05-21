#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int countSwap = 0;
int countComparison = 0;

void resetCount ()
{
    countSwap = 0;
    countComparison = 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    countSwap++;
}

void show()
{
    cout << "A R R A Y setelah di-sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\njumlah Penukaran       : " << countSwap << endl;
    cout << "Jumlah perbandingan    : " << countComparison << endl;
}

void BubbleSort()
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            countComparison++;
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void SelectionSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int Indexterbawah = i;
        for (int j = i + 1; j < n; j++)
        {
            countComparison++;
            if (arr[j] < arr[Indexterbawah])
                Indexterbawah = j;
        }

        if (Indexterbawah != i)
            swap(&arr[i], &arr[Indexterbawah]);
    }
}

void InsertionSort()
{
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0 && arr[j] > arr[j+1]; j--,countComparison++)
            swap(&arr[j], &arr[j+1]);
}

void Merge(int aleft, int aright, int bleft, int bright)
{
    vector<int> temp;
    int aIndex = aleft, bIndex = bleft;
    while (aIndex <= aright && bIndex <= bright)
    {
        if (arr[aIndex] <= arr[bIndex])
        {
            temp.push_back(arr[aIndex]);
            aIndex++;
        }
        else
        {
            temp.push_back(arr[bIndex]);
            bIndex++;
        }
    }

    while (aIndex <= aright)
    {
        temp.push_back(arr[aIndex]);
        aIndex++;
    }
    while (bIndex <= bright)
    {
        temp.push_back(arr[bIndex]);
        bIndex++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[aleft + i] = temp[i];
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
        arr.push_back(t);
    }
    resetCount();
    BubbleSort();
    // SelectionSort();
    // InsertionSort();
    // MergeSort(0, n - 1);
    show();
    return 0;
}