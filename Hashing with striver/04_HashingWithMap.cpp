#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n, q;
    cout << "Enter the size of Array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }

    cout << "Enter the value times: ";
    cin >> q;
    while (q--)
    {
        int number;
        cout << "Enter the number: ";
        cin >> number;
        cout << mpp[number] << endl;
    }

    cout << "Let's iterate the map:\n";
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second<<endl;
    }
    return 0;
}