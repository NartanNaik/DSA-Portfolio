#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
long long findMaxSubArray(vector<int> &a, int n)
{
    long long sum = 0, maxi = LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
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
    long long MaxArray = findMaxSubArray(a, n);
    cout << "Maximum SubArray is: " << MaxArray;
    return 0;
}