#include <iostream>
#include <vector>
using namespace std;
void hashingCount(int n, int m, vector<int> &a)
{
    int hash[13] = {0};
    for (int i = 0; i < m; i++)
    {
        hash[a[i]] += 1;
    }

    int q;
    cout << "Enter Queue: ";
    cin >> q;
    while (q--)
    {
        int num;
        cout << "Enter number: ";
        cin >> num;
        cout << hash[num]<<"\n";
    }
}
int main()
{
    int n, m;
    cout << "Enter the size of Array: ";
    cin >> m;
    vector<int> a(m);
    cout << "Enter array Element: \n";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    hashingCount(n, m, a);
    return 0;
}