#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
int findMPowerN(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
        {
            return 2;
        }
    }
    if (ans == m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int findAns(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = findMPowerN(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cout << "Enter the M: ";
    cin >> m;
    cout << "Enter the N: ";
    cin >> n;
    int ans = findAns(n, m);
    cout << "The " << n << " root of " << m << " is " << ans;
    return 0;
}