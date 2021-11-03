// Lab_6-1_rec
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}


void Sort(int* a, const int size, int i, int j, int& k)
{
    if (a[j] > a[j + 1]) 
    { 
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
        k = 1;
    }
    if (j < size - i - 1)
        Sort(a, size, i, j + 1, k);
    if (k == 0) 
        return; 
    if (i < size - 1) 
    {
        k = 0; 
        Sort(a, size, i + 1, 0, k); 
    }
}


void result(int a[], const int size, int i) {
    if (i < size)
    {
        if (a[i] % 2 != 0 || i % 8 == 0)
            a[i] = 0;
        return result(a, size, i + 1);
    }
}
int Sum(int* a, const int size, int i)
{
    if (i < size)
        return a[i] + Sum(a, size, i + 1);
    else
        return 0;
}


int main()
{
    srand((unsigned)time(NULL));

    const int n = 25;

    int c[n];
    int Low = 5;
    int High = 90;
    Create(c, n, Low, High, 0);

    int k = 0;
    Sort(c, n, 1, 0, k);

    cout << c[0];
    for (int i = 1; i < sizeof c / sizeof(int);) cout << ' ' << c[i++];
    cout << endl;

    result(c, n, 0);

    cout << c[0];
    for (int i = 1; i < sizeof c / sizeof(int);) cout << ' ' << c[i++];
    cout << endl;
    int sum = Sum(c, n, 0);

    cout << "Sum = " << sum << endl;
}

