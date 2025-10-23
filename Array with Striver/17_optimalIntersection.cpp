#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>

using namespace std;

vector<int> intersectoinOPtimally(vector<int> &a, vector<int> &a2)
{
    int i = 0;
    int j = 0;
    int n = a.size();
    int n2 = a2.size();
    vector<int> ansArray;
    while (i < n && j < n2)
    {
        if (a[i] < a2[j])
        {
            i++;
        }
        else if (a2[j] < a[i])
        {
            j++;
        }
        else
        {
            ansArray.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ansArray;
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

    auto answer = intersectoinOPtimally(a, a2);
    cout << "After intersecting optimally:\n";
    for (auto it : answer)
    {
        cout << it << " ";
    }
    return 0;
}