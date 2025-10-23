#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int findDays(vector<int> &a, int cap)
{
    int days = 1, load = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] + load > cap)
        {
            days += 1;
            load = a[i];
        }
        else
        {
            load += a[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &a, int d)
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(a, mid);
        if (numberOfDays <= d)
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
    int days;
    cout << "Enter the number of days: ";
    cin >> days;
    int ans = leastWeightCapacity(a, days);
    cout << "to carry these weight least weight is: " << ans;
    return 0;
}