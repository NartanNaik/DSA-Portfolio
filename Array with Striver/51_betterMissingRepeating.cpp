#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<int> findMissingAndReapiting(vector<int> &a, int n)
{
    vector<int> hash(n + 1, 0);
    int repeating = -1, missing = -1;
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
        {
            repeating = i;
        }
        else if (hash[i] == 0)
        {
            missing = i;
        }
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {repeating, missing};
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
    vector<int> result = findMissingAndReapiting(a, n);
    cout << "The missing element: " << result[1] << "\n";
    cout << "The repeating element: " << result[0] << "\n";
    return 0;
}