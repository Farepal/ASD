#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int countSwap = 0;
int countComparison = 0; // perbandingan antar data array

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
    int low = 0, high = n - 1, mid;
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
{                     // a maksudnya subarray kiri dan b itu subarray kanan
    if (left < right) // tidak akan menyorting satu data saja
    {
        int mid = (left + right) / 2;
        // PARTISI
        MergeSort(left, mid);
        MergeSort(mid + 1, right);

        // Algoritma Merge
        // Merge(left, mid, mid + 1, right)
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
    // Operasi partisi,
    // operasi mencari indeks pivot, menempatkan subarray yg lebih kecil dari pivot di kiri
    // dan menempatkan subarray yang lebih besar dari pivot di kanan
    if (left < right)
    {
        int pivot = arr[right];
        int indexPositionShouldBe = left;  // pivoIndex yang akan digantikan
        for (int i = left; i < right; i++) // sampai right, karena right itu indeks pivot
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
    vector<int> gelas(k, 0);

    for (int i = 0; i < n; i++)
        gelas[arr[i]]++;

    for (int i = 1; i < k; i++)
        gelas[i] = gelas[i] + gelas[i - 1];

    vector<int> temp(n);
    for (int j = n - 1; j >= 0; j--)
    {
        temp[gelas[arr[j]] - 1] = arr[j];
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
        vector<int> digitCount(10, 0); // menggunakan 10 karena angka satu digit tertinggi adalah 9
        for (int i = 0; i < n; i++)
        {
            getOneDigit = (arr[i] / pembagi) % 10;
            digitCount[getOneDigit]++;
        }

        for (int j = 1; j < 10; j++)
            digitCount[j] = digitCount[j] + digitCount[j - 1];

        // create temporary array
        vector<int> temp(n);
        // kenapa dimulai dari n-1 karena yg sebelum tertinggi tetaplah tertinggi saat ada yg sama
        for (int i = n - 1; i >= 0; i--)
        {
            getOneDigit = (arr[i] / pembagi) % 10;
            temp[digitCount[getOneDigit] - 1] = arr[i];
            digitCount[getOneDigit]--;
        }
        arr = temp;
    }
}
void heapSort()
{
    // Bulid max Heap
    //Build max Heap menggunakan algporitma heapify
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int largestIndex = i;
        //di sini largestIndex bakal terus pindah ke bawah
        //heapify algorithm
        while (true)
        {
            int indexOfRootThatWillSwap = largestIndex;
            int indLeftChild = largestIndex * 2 + 1;
            int indRightChild = largestIndex * 2 + 2;

            if (indLeftChild < n)
                if (arr[indLeftChild] > arr[largestIndex])
                {
                    largestIndex = indLeftChild;
                    countComparison++;
                }

            if (indRightChild < n)
                if (arr[indRightChild] > arr[largestIndex])
                {
                    largestIndex = indRightChild;
                    countComparison++;
                }

            if (largestIndex != indexOfRootThatWillSwap)
                swap(&arr[largestIndex], &arr[indexOfRootThatWillSwap]);
            else
                break;
        }
    }

    int tempSize = n;
    for (int szTemp = n; ;)
    {
        swap(&arr[0], &arr[szTemp - 1]);
        szTemp--;
        if (szTemp <= 1)
            break;
        
        //heapify algorithm kepada array dengan ukuran szTemp
        int largestIndex = 0;
        while (true)
        {
            int indexOfRootThatWillSwap = largestIndex;
            int indLeftChild = largestIndex * 2 + 1;
            int indRightChild = largestIndex * 2 + 2;

            if (indLeftChild < szTemp)
                if (arr[indLeftChild] > arr[largestIndex])
                {
                    largestIndex = indLeftChild;
                    countComparison++;
                }

            if (indRightChild < szTemp)
                if (arr[indRightChild] > arr[largestIndex])
                {
                    largestIndex = indRightChild;
                    countComparison++;
                }

            if (largestIndex != indexOfRootThatWillSwap)
                swap(&arr[largestIndex], &arr[indexOfRootThatWillSwap]);
            else
                break;
        }
    }
}

int main()
{
    input();
    vector <int> tempArr = arr;
    cout << "PICK THE NUMBER OF SORT BY THE NUMBER" << endl;
    cout << "By the way, just using non negative number for Radix Sort" << endl;
    cout << "1. Bubble Sort 2. Selection Sort 3. Insertion Sort" << endl;
    cout << "4. Quick Sort 5. Merge Sort 6. Shell Sort" << endl;
    cout << "7. Radix Sort 8. Heap Sort" << endl;
    int pilihan;
    cout << "\nSilahkan pilih angka : "; 
    cin >> pilihan;
    cout << endl;
    
    while (true)
    {
        if (pilihan == 1)
        {
            cout << "Bubble Sort" << endl;
            resetCount();
            BubbleSort();
            show();
        }
        else if (pilihan == 2)
        {
            cout << "Selection Sort" << endl;
            resetCount();
            SelectionSort();
            show();
        }
        else if (pilihan == 3)
        {
            cout << "Insertion Sort" << endl;
            resetCount();
            InsertionSort();
            show();
        }
        else if (pilihan == 4)
        {
            cout << "Quick Sort" << endl;
            resetCount();
            quickSort(0, n-1);
            show();
        }
        else if (pilihan == 5)
        {
            cout << "Merge Sort" << endl;
            resetCount();
            MergeSort(0, n-1);
            show();
        }
        else if (pilihan == 6)
        {
            cout << "Shell Sort" << endl;
            resetCount();
            shellSort();
            show();
        }
        else if (pilihan == 7)
        {
            cout << "Radix Sort" << endl;
            resetCount();
            radixSort();
            show();
        }
        else if (pilihan == 8)
        {
            cout << "Heap Sort" << endl;
            resetCount();
            heapSort();
            show();
        }
        arr = tempArr;
        cout << "\nSilahkan pilih angka : "; 
        cin >> pilihan;
        cout << endl;
    }
    // resetCount();
    // BubbleSort();
    // SelectionSort();
    // InsertionSort();
    // countingSort(1001);
    // quickSort(0, n - 1);
    // MergeSort(0, n - 1);
    // shellSort();
    // radixSort();
    // heapSort();
    show();
    // showTLX();
    return 0;
}