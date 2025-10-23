#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

vector<int> anotheroptimalForRearrange(vector<int> &a, int n)
{
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            pos.push_back(a[i]);
        else
            neg.push_back(a[i]);
    }

    int i = 0, index = 0;
    // Alternate placement
    while (i < pos.size() && i < neg.size())
    {
        a[index++] = pos[i];
        a[index++] = neg[i];
        i++;
    }

    // Remaining elements
    while (i < pos.size())
        a[index++] = pos[i++];

    while (i < neg.size())
        a[index++] = neg[i++];

    return a;
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
    vector<int> array = anotheroptimalForRearrange(a, n);
    for (auto it : array)
    {
        cout << it << " ";
    }
    return 0;
}