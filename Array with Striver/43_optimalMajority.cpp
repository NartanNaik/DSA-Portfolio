#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> majorityOptimal(vector<int> &a, int n)
{
    int count1 = 0, count2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && el2 != a[i])
        {
            count1 = 1;
            el1 = a[i];
        }
        else if (count2 == 0 && el1 != a[i])
        {
            count2 = 1;
            el2 = a[i];
        }
        else if (a[i] == el1)
        {
            count1++;
        }
        else if (a[i] == el2)
        {
            count2++;
        }
        else
        {
            count1--, count2--;
        }
    }
    vector<int> ls;
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == a[i])
        {
            count1++;
        }
        if (el2 == a[i])
        {
            count2++;
        }
    }
    int mini = (int)(n / 3) + 1;
    if (count1 >= mini)
    {
        ls.push_back(el1);
    }
    if (count2 >= mini)
    {
        ls.push_back(el2);
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
    vector<int> optimal = majorityOptimal(a, n);
    cout << "The majority Elemenets are: \n";
    for (auto it : optimal)
    {
        cout << it << " ";
    }
    return 0;
}