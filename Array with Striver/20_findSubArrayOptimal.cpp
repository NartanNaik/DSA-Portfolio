#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
int optimalSolutionForFindSubArray(vector<int> &a, int k)
{
    int n = a.size();
    int maxLen = 0, left = 0, right = 0, sum = a[0];
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += a[right];
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
    cout<<"Enter K: ";
    cin>>k;
    int getK = optimalSolutionForFindSubArray(a,k);
    cout<<"Optimal solution for find a sub array with sum k is: "<<getK;
    return 0;
}