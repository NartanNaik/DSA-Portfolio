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

int findMin(vector<int> &a, int n)
{
    int low = 0, high = n - 1, ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[low] <= a[mid])
        {
            ans = min(ans, a[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            ans = min(ans, a[mid]);
        }
    }
    return ans;
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
    int ans = findMin(a, n);
    cout << "Minimum in the Array in this rotated array is: " << ans;
    return 0;
}