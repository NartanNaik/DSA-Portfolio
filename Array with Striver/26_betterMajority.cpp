#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
int betterMajority(vector<int> &a, int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            return it.first;
        }
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
    int num = betterMajority(a, n);
    cout << num;
    return 0;
}