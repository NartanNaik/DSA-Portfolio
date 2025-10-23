#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;

vector<int> optimalUnion(vector<int> &a, vector<int> &a2)
{
    int n = a.size();
    int n2 = a2.size();
    int i = 0;
    int j = 0;
    vector<int> unionArray;
    while (i < n && j < n2)
    {
        if (a[i] < a2[j])
        {
            if (unionArray.size() == 0 || unionArray.back() != a[i])
            {
                unionArray.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArray.size() == 0 || unionArray.back() != a2[j])
            {
                unionArray.push_back(a2[j]);
            }
            j++;
        }
    }
    while (j < n2)
    {
        if (unionArray.size() == 0 || unionArray.back() != a2[j])
        {
            unionArray.push_back(a2[j]);
        }
        j++;
    }
    while (i < n)
    {
        if (unionArray.size() == 0 || unionArray.back() != a[i])
        {
            unionArray.push_back(a[i]);
        }
        i++;
    }

    return unionArray;
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

    int n2;
    cout << "Enter the size of the Array: ";
    cin >> n2;
    vector<int> a2(n2);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }
    vector<int> unionA = optimalUnion(a, a2);
    cout << "After union: \n";
    for (auto it : unionA)
    {
        cout << it << " ";
    }
    return 0;
}