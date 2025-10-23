#include <iostream>
#include <string>
using namespace std;

void backTrack(int nu,int n)
{
    if (nu<0)
    {
        return;
    }
    cout << nu << endl;
    backTrack(nu-1,n);
}

int main()
{
    int n,nu;
    cout << "Enter Num: ";
    cin >> n;
    nu=n;
    backTrack(nu,n);
    return 0;
}