#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (int i = 0; i < a.size(); i += 2)
    // {
    //     if (a.size() % 2 != 0 && i == a.size() - 1)
    //     {
    //         break;
    //     }
    //     swap(a[i], a[i + 1]);
    // }
    for (int i = 0,j=a.size()-1; i!=j; i++,j--)
    {
        swap(a[i], a[j]);
    }
    
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}