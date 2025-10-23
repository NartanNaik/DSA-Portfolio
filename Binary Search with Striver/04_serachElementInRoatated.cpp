#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TC -> O(log2N)
// SC -> O(1)

int search(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
        {
            return mid;
        }

        if (a[low] <= a[mid])
        {
            if (a[low] <= x && x <= a[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (a[mid] <= x && x <= a[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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
    cout << "Enter the Rotated Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cout << "Enter x: ";
    cin >> x;
    int ans = search(a, n, x);
    cout << "The element is in: " << ans;
    return 0;
}