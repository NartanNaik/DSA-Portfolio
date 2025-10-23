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



int sumByD(vector<int> &a, int div)
{
    int sum = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        sum = sum + ceil((double)(a[i]) / (double)(div));
    }
    return sum;
}

int smallestDevisor(vector<int> &a, int limit)
{
    int low = 1, high = *max_element(a.begin(), a.end());
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumByD(a, mid) <= limit)
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
    int limit;
    cout << "Enter Limit: ";
    cin >> limit;
    int ans = smallestDevisor(a, limit);
    cout << "Smallest divisor is: " << ans;
    return 0;
}