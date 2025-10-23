#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

void optimalMerge(vector<int> &a1, vector<int> &a2, int n, int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (a1[left] > a2[right])
        {
            swap(a1[left], a2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
}

int main()
{
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    vector<int> a1(n);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }

    int m;
    cout << "Enter the size of the Array: ";
    cin >> m;
    vector<int> a2(m);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }
    optimalMerge(a1, a2, n, m);
    cout << "Merged Sorted Array:\n";
    for (auto it : a1)
    {
        cout << it << " ";
    }
    for (auto its : a2)
    {
        cout << its << " ";
    }
    return 0;
}