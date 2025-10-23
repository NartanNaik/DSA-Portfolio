#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
void bruteForceMajority(vector<int> &a, int n)
{
    int mid = n / 2;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == a[i])
            {
                count++;
            }
        }
        if (count > mid)
        {
            cout << "Majority Element is: " << a[i];
            return;
        }
    }
    cout << "No Majority Element Found...\n";
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
    bruteForceMajority(a, n);
    return 0;
}