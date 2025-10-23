#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int secondLargest(vector<int> &a, int n)
{
    int largest = a[0];
    int secLarge = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            secLarge = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secLarge)
        {
            secLarge = a[i];
        }
    }
    return secLarge;
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
    int second = secondLargest(a, n);
    cout << "The Second Largest Element is: " << second;
    return 0;
}