#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TC -> O(N)
// SC -> O(1)

int maxProdutSubArray(vector<int> &a, int n)
{
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
        {
            pre = 1;
        }
        if (suff == 0)
        {
            suff = 1;
        }
        pre = pre * a[i];
        suff = suff * a[n - i - 1];
        ans = max(ans, max(pre, suff));
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
    int ans = maxProdutSubArray(a, n);
    cout << "The maximum subarray's product is: " << ans;
    return 0;
}