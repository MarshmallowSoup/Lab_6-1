// Lab_6-1.cpp

#include <iostream>
#include <time.h>
using namespace std;


void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
   }


int Sum(int *p, const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (p[i] % 2 == 0 || !(i % 8 == 0) ){
            sum += p[i];
            p[i] = 0;
        }

    return sum;

}void result(int* p, const int n){
    for (int i = 0; i < n; i++)
        if (p[i] % 2 == 0 || !(i % 8 == 0) ) {
                        p[i] = 0;
        }


}
int Count(int* p, const int n){
    int k = 0;
    for (int i = 0; i < n; i++)
        if (p[i] % 2 == 0 || !(i % 8 == 0) ) {
            k++;
        }
    return k;
}


int main()
{
    srand((unsigned)time(NULL)); 

    const int n = 25;

    int c[n];
    int Low = 5;
    int High = 90;

    Create(c, n, Low, High);

    cout << c[0];
    for (int i = 1; i < sizeof c / sizeof(int);) cout << ' ' << c[i++];
    cout << endl;
   
    int sum = Sum(c,n);
    cout << "Sum = " << sum << endl;

    int count = Count(c, n);

    cout << "Number of elements = " << count << endl;
    
    result(c, n);

    cout << c[0];
    for (int i = 1; i < n; i++)     
    cout << ' ' << c[i];
    cout << endl;


    return 0;

}
