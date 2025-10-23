#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
int findSquareRootOfAnElement(int n)
{
    int low = 0, high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = (mid * mid);
        if (val <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n;
    cout << "Enter an number: ";
    cin >> n;
    int ans = findSquareRootOfAnElement(n);
    cout << "Squareroot of " << n << " is: " << ans;
    return 0;
}