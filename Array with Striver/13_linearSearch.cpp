#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
int findLin(vector<int> &a, int n, int find)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == find)
        {
            return i;
        }
    }
    return -1;
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
    int find;
    cout << "Enter the number to find: ";
    cin >> find;
    int got = findLin(a, n, find);
    cout << "This number " << find << " is in " << got << "th index";
    return 0;
}