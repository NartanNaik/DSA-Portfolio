#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
void missingElement(vector<int> a, int n)
{
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[a[i]] = 1;
    }
    cout << "Missing Elements:\n";
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
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
    missingElement(a,n);
    return 0;
}