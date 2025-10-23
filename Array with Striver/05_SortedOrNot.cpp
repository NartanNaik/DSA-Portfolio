#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;
void sortedOrNot(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
        }
        else
        {
            cout << "This is not Sorted";
            return;
        }
    }
    cout << "This is Sorted";
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
    sortedOrNot(a, n);
    return 0;
}