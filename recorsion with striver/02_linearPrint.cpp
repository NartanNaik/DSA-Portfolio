#include <iostream>
#include <string>
using namespace std;

void printNUM(int nu,int n)
{
    if (nu > n)
    {
        return;
    }
    cout << nu << endl;
    nu++;
    printNUM(nu,n);
}

int main()
{
    int n,nu;
    cout << "Enter Start: ";
    cin >> nu;
    cout << "Enter End: ";
    cin >> n;
    printNUM(nu,n);
    return 0;
}