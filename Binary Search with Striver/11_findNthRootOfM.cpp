#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
int findMPowerN(int mid, int n)
{
    long long ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= mid;
            n = n - 1;
        }
        else
        {
            mid *= mid;
            n = n / 2;
        }
    }
}

// this might overflow so prefer 12th code

int findAns(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = findMPowerN(mid, n);
        if (midN == m)
        {
            return mid;
        }
        else if (midN < m)
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