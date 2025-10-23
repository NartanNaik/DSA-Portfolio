#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

int firstOccurence(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> firstLastOccurence(vector<int> &a, int n, int x)
{
    int first = firstOccurence(a, n, x);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurence(a, n, x);
    return {first, last};
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
    cout << "Enter X: ";
    cin >> x;
    pair<int, int> answer = firstLastOccurence(a, n, x);
    cout << "First Occurence is: " << answer.first << " and Last Occurence is: " << answer.second;
    return 0;
}