#include <iostream>
#include <vector>
using namespace std;
int countNumber(int n, vector<int> &a, int m)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i]==n)
        {
            count += 1;
        }
    }
    return count;
}
int main()
{
    int n, m;
    cout << "Enter the Array size: ";
    cin >> m;
    vector<int> a(m);
    cout << "Enter the Array Element: \n";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the number to find in array: ";
    cin >> n;
    cout << countNumber(n, a, m);
    return 0;
}