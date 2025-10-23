#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
int optimalRemDub(vector<int> &a, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[i] != a[j])
        {
            a[i + 1] = a[j];
            i++;
        }
    }
    return i + 1;
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
    int optimal = optimalRemDub(a, n);
    cout << "The UniqueElements Are: " << optimal;
    return 0;
}