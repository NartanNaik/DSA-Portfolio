#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

int subarrayWithXOR(vector<int> &a, int n, int k)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
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
    int k;
    cout << "Enter k: ";
    cin >> k;
    int ans = subarrayWithXOR(a, n, k);
    cout << "the number of subArray which have xor k is: " << ans;
    return 0;

    // TN-> O(n) or O(nlogn) depends on mapps time complexity
    // SC->O(n) at the worst case 
//ex: 
// Enter the size of the Array: 5
// Enter the Array: 
// 4
// 2
// 2
// 6
// 4
// Enter k: 6
// the number of subArray which have xor k is: 4
}