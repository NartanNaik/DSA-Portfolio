#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// TC -> O(N*log2(max-min+1))

bool possible(vector<int> &a, int day, int m, int k)
{
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> &a, int m, int k)
{
    long long val = m * 1LL * k * 1LL;
    if (val > a.size())
    {
        return -1;
    }
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        mini = min(mini, a[i]);
        maxi = min(maxi, a[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(a, mid, m, k))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
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
    sort(a.begin(), a.end());
    int m, k;
    cout << "Enter the number of Buckes: ";
    cin >> m;
    cout << "Enter the number of flowers each bucke contains: ";
    cin >> k;

    int ans = roseGarden(a, m, k);

    cout << "The number of buckes can be is: " << ans;

    return 0;
}