#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

int countSubArraysWithSumK(vector<int> &arr, int n, int k)
{
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum] += 1;
    }
    return count;
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
    int sum;
    cout << "Enter sum: ";
    cin >> sum;
    int ans = countSubArraysWithSumK(a, n, sum);
    cout << "There is " << ans << " subaarrays with sum " << sum;
    return 0;
}