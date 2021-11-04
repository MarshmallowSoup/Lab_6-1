// Lab_6-1.cpp

#include <iostream>
#include <time.h>
using namespace std;


void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
   }


void QuickSort(int* arr, int first, int last)
{
    int l = first, r = last, p = arr[(first + last) / 2];
    do {
        while (arr[l] < p) l++;
        while (arr[r] > p) r--;
        if (l <= r)
        {
            if (arr[l] > arr[r]) swap(arr[l], arr[r]);
            l++;
            r--;
        }
    } while (l <= r);
    if (l < last)
        QuickSort(arr, l, last);
    if (first < r)
        QuickSort(arr, first, r);
}

int Sum(int *p, const int n, int &k) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (p[i] % 2 == 0 || i % 8 != 0 || i == 0){
            sum += p[i];
            k++;
            p[i] = 0;
        }

    return sum;

}

int main()
{
    srand((unsigned)time(NULL)); 

    const int n = 25;

    int c[n];
    int Low = 5;
    int High = 90;

    Create(c, n, Low, High);
    QuickSort(c, 0, n - 1);

    cout << c[0];
    for (int i = 1; i < sizeof c / sizeof(int);) cout << ' ' << c[i++];
    cout << endl;
   
    int k = 0;
    int sum = Sum(c,n,k);
    cout << "Sum = " << sum << endl;
    cout << "Number of elrments = " << k << endl;

    cout << c[0];
    for (int i = 1; i < n; i++)     
    cout << ' ' << c[i];
    cout << endl;


    return 0;

}
