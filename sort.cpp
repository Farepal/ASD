#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int countSwap = 0;
int countComparison = 0;//perbandingan antar data array

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
}
void resetCount()
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
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "jumlah Penukaran       : " << countSwap << endl;
    cout << "Jumlah perbandingan    : " << countComparison << endl;
}
void showTLX()
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int getMax()
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
int linearSearch(int angka)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == angka)
            return i;
    return -1;
}
int binarySearch(int angka)
{
    int low = 0, high = n-1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == angka)
            return mid;
        else if (arr[mid] > angka)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void BubbleSort()
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            ++countComparison;
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
            ++countComparison;
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
        for (int j = i - 1; j >= 0; j--)
        {
            ++countComparison;
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
            else
                break;
        }
}
void MergeSort(int left, int right)
{//a maksudnya subarray kiri dan b itu subarray kanan
    if (left < right) // tidak akan menyorting satu data saja
    {
        int mid = (left + right) / 2;
        //PARTISI
        MergeSort(left, mid);
        MergeSort(mid + 1, right);

        // Algoritma Merge
        //Merge(left, mid, mid + 1, right)
        vector<int> temp;
        int aIndex = left, bIndex = mid + 1;

        while (aIndex <= mid && bIndex <= right)
        {
            ++countComparison;
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
        // sisaan, sisaan pasti berupa angka yang paling gede
        while (aIndex <= mid)
        {
            temp.push_back(arr[aIndex]);
            aIndex++;
        }

        while (bIndex <= mid + 1)
        {
            temp.push_back(arr[bIndex]);
            bIndex++;
        }

        for (int i = 0; i < temp.size(); i++)
            arr[left + i] = temp[i];
    }
}
void quickSort(int left, int right)
{
    //Operasi partisi, 
    //operasi mencari indeks pivot, menempatkan subarray yg lebih kecil dari pivot di kiri
    //dan menempatkan subarray yang lebih besar dari pivot di kanan
    if (left < right)
    {
        int pivot = arr[right];
        int indexPositionShouldBe = left;//pivoIndex yang akan digantikan
        for (int i = left; i < right; i++)//sampai right, karena right itu indeks pivot
        {
            countComparison++;
            if (arr[i] < pivot)
            {
                swap(&arr[indexPositionShouldBe], &arr[i]);
                indexPositionShouldBe++;
            }
        }
        swap(&arr[indexPositionShouldBe], &arr[right]);
        quickSort(left, indexPositionShouldBe - 1);
        quickSort(indexPositionShouldBe + 1, right);
    }
}
void countingSort(int k)
{
    vector <int> gelas (k, 0);

    for (int i = 0; i < n; i++)
        gelas[arr[i]]++;

    for (int i = 1; i < k; i++)
        gelas[i] = gelas[i] + gelas[i-1];

    vector <int> temp (n);
    for (int j = n-1; j >= 0; j--)
    {
        temp[gelas[arr[j]]-1] = arr[j];
        gelas[arr[j]]--;
    }
    arr = temp;
}
void shellSort()
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = 0; (i + gap) < n; i++)
        {
            int j = i + gap;
            while ((j - gap) >= 0)
            {
                countComparison++;
                if (arr[j] < arr[j - gap])
                {
                    swap(&arr[j], &arr[j - gap]);
                    j -= gap;
                }
                else
                    break;
            }
        }
    }
}
void radixSort()
{
    int mx = getMax(), getOneDigit;
    for (int pembagi = 1; mx / pembagi > 0; pembagi *= 10)
    {
        ////ITS CALLED COUNTING SORT BROO////
        vector <int> digitCount (10, 0);//menggunakan 10 karena angka satu digit tertinggi adalah 9
        for (int i = 0; i < n; i++)
        {
            getOneDigit = (arr[i] / pembagi) % 10;
            digitCount[getOneDigit]++;
        }

        for (int j = 1; j < 10; j++)
            digitCount[j] = digitCount[j] + digitCount[j-1];

        //create temporary array
        vector <int> temp(n);
        //kenapa dimulai dari n-1 karena yg sebelum tertinggi tetaplah tertinggi saat ada yg sama
        for (int i = n-1; i >= 0; i--)
        {
            getOneDigit = (arr[i] / pembagi) % 10;
            temp[digitCount[getOneDigit] - 1] = arr[i];
            digitCount[getOneDigit]--;
        }
        arr = temp;
    }
}


int main()
{
    input();
    // resetCount();
    // BubbleSort();
    // SelectionSort();
    // InsertionSort();
    // countingSort(1001);
    // quickSort(0, n - 1);
    // MergeSort(0, n - 1);
    // shellSort();
    // radixSort();
    // show();
    showTLX();
    return 0;
}