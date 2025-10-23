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

int numberOfGasStationRequired(long double distance, vector<int> &a)
{
    int cnt = 0;
    for (int i = 1; i < a.size(); i++)
    {
        int numberInBetween = ((a[i] - a[i - 1]) / distance);
        if ((a[i] - a[i - 1]) / distance == numberInBetween * distance)
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &a, int k)
{
    int n = a.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(a[i + 1] - a[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationRequired(mid, a);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
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
    cout << "Enter the K: ";
    cin >> k;
    long double ans = minimiseMaxDistance(a, k);
    cout << "The answer is: " << ans;
    return 0;
}