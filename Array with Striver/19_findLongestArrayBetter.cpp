#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
int longestSubArrayWithSumK(vector<int> &a, int k)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
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
    cout << "Enter K: ";
    cin >> k;
    int gotK = longestSubArrayWithSumK(a, k);
    cout << "Longest sub array with sum k is: " << gotK;
    return 0;
}