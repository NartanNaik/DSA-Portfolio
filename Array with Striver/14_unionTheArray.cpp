#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
vector<int> unionArray(vector<int> &a, int n, vector<int> &a2, int n2)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(a2[i]);
    }
    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
    }
    return temp;
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

    int n2;
    cout << "Enter the another size of the Array: ";
    cin >> n2;
    vector<int> a2(n2);
    cout << "Enter the another Array: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }

    vector<int> uni = unionArray(a, n, a2, n2);
    cout << "Array after union: ";
    for (auto it : uni)
    {
        cout << it << " ";
    }
    return 0;
}