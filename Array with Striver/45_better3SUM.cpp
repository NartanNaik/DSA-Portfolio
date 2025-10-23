#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> better3Sum(vector<int> &a, int n)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(a[i] + a[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {a[i], a[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
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
    vector<vector<int>> solution = better3Sum(a, n);
    cout << "Unique triplates that sum to zero are:\n";
    for (auto &triplet : solution)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout<<"\n";
    }
    return 0;
}