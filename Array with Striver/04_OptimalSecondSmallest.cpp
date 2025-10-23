#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;
int secondSmallest(vector<int> &a, int n)
{
    int firstSmallest = a[0];
    int secSmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < firstSmallest)
        {
            secSmallest = firstSmallest;
            firstSmallest = a[i];
        }
        else if (a[i] != firstSmallest && a[i] < secSmallest)
        {
            secSmallest = a[i];
        }
    }
    return secSmallest;
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
    cout << "The second smallest Element is: " << secondSmallest(a, n);
    return 0;
}