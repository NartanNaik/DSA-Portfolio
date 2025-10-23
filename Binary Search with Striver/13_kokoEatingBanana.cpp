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

// TC -> [O(N)*log2(maxEl)]

int findMax(vector<int> &a)
{
    int maxi = INT_MIN;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &a, int hourly)
{
    int totalH = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)a[i] / (double)hourly);
    }
    return totalH;
}

int minimumRateToEatBanana(vector<int> &a, int h)
{
    int low = 1, high = findMax(a);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(a, mid);
        if (totalH <= h)
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
    int h;
    cout << "Enter the hour: ";
    cin >> h;

    int ans = minimumRateToEatBanana(a, h);
    if (ans == -1)
    {
        cout << "It is not possible to eat all bananas in " << h << " hours.";
    }
    else
    {
        cout << "The minimum banana koko can eat is: " << ans << " in " << h << " hours";
    }
    return 0;
}