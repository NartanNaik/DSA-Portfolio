#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
void maximumPrice(vector<int> &a, int n)
{
    int mini = a[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = a[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, a[i]);
    }
    cout << "The Max Profit is: " << maxProfit;
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
    maximumPrice(a, n);
    return 0;
}