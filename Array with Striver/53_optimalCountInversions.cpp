#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TC->O(NlongN);
// SC->O(N);

int Merge(vector<int> &a, int low, int mid, int high)
{
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &a, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }
    int mid = (low + high) / 2;
    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid + 1, high);
    cnt += Merge(a, low, mid, high);
    return cnt;
}

int countInversion(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
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
    int value = countInversion(a, n);
    cout << "The value is: " << value;
    return 0;
}