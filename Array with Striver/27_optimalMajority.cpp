#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
int optimalmajority(vector<int> &a, int n)
{
    int count = 0, count1 = 0, el;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = a[i];
        }
        else if (a[i] == el)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == el)
        {
            count1++;
        }
    }
    if (count1 > n / 2)
    {
        return el;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int getAns = optimalmajority(a,n);
    cout<<getAns;
    return 0;
}