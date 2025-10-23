#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC->2*O(log2N)
// SC ->O(1)

int findLowerBound(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int findUpperBound(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> findFirstAndLast(vector<int> &a, int n, int k)
{
    int lb = findLowerBound(a, n, k);
    if (lb == n || a[lb] != k)
    {
        return {-1, -1};
    }
    else
    {

        return {lb, findUpperBound(a, n, k) - 1};
    }
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
    int x;
    cout << "Enter x element: ";
    cin >> x;
    pair<int, int> answer = findFirstAndLast(a, n, x);
    cout << "First occurence is: " << answer.first << " and Last Occrurance is: " << answer.second;
    return 0;
}