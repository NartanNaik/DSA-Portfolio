#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> getMajorityBetter(vector<int> &a, int n)
{
    vector<int> ls;
    map<int, int> mpp;
    int mini = (int)(n / 3) + 1;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
        if (mpp[a[i]] == mini)
        {
            ls.push_back(a[i]);
        }
        if (ls.size() == 2)
        {
            break;
        }
    }
    sort(ls.begin(), ls.end());
    return ls;
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
    return 0;
}