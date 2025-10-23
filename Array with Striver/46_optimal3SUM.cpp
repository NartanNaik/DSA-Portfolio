#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> optimal3Sum(vector<int> &a, int n)
{
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {a[i], a[j], a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && a[j] == a[j - 1])
                {
                    j++;
                }
                while (j < k && a[k] == a[k - 1])
                {
                    k--;
                }
            }
        }
    }
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
    vector<vector<int>> soulution = optimal3Sum(a, n);
    cout << "The answer: \n";
    for (auto &triplet : soulution)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

    //input: -1 0 1 2 -1 -4
    //output: -1 -1 2
    //        -1  0 1

    //TC-> (nlogn)+o(n^2)
    //SC-> O(no.triplets)
}