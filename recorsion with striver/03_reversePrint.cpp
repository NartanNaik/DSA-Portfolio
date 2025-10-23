#include <iostream>
#include <string>
using namespace std;

void printNUM2(int nu,int n)
{
    if (nu < n)
    {
        return;
    }
    cout << nu << endl;
    nu--;
    printNUM2(nu,n);
}

int main()
{
    int n,nu;
    cout << "Enter Start: ";
    cin >> n;
    cout << "Enter End: ";
    cin >> nu;
    printNUM2(nu,n);
    return 0;
}