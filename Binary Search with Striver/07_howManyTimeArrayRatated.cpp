#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

int findRoatationCount(vector<int> &a, int n)
{
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[low] <= a[high])
        {
            if (a[low] < ans)
            {
                index = low;
                ans = a[low];
            }
            break;
        }
        if (a[low] <= a[mid])
        {
            if (a[low] < ans)
            {
                index = low;
                ans = a[low];
            }
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            if (a[mid] < ans)
            {
                index = mid;
                ans = a[mid];
            }
        }
    }
    return index;
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
    int ans = findRoatationCount(a, n);
    cout << "This array rotated " << ans << " times";
    return 0;
}