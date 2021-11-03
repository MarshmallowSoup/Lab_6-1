// Lab_6-1.cpp

#include <iostream>
#include <algorithm>
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


void result(int a[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0 || i % 8 == 0)
            a[i] = 0;
    }

}

int Sum(const int *p, const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += p[i];
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

    result(c, n);

    cout << c[0];
    for (int i = 1; i < sizeof c / sizeof(int);) cout << ' ' << c[i++];
    cout << endl;
    int sum = Sum(c,n);
    cout << "Sum = " << sum << endl;

    return 0;

}
