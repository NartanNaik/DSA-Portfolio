#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TC-> O(log2N)

int findPeak(vector<int> &a, int n)
{
    if (n == 1)
        return a[0];
    if (a[0] > a[1])
        return a[0];
    if (a[n - 1] > a[n - 2])
        return a[n - 1];
    int low = 0, high = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
        {
            return a[mid];
        }
        else if (a[mid] > a[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
    int ans = findPeak(a, n);
    cout << "The peak element in thr array is: " << ans;
    return 0;
}