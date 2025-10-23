#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
vector<int> leftRotate(vector<int> &a, int n)
{
    int temp = a[0];
    for (int i = 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    a[n - 1] = temp;
    return a;
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
    leftRotate(a, n);
    for (auto it : a)
    {
        cout << it<<" ";
    }
    return 0;
}