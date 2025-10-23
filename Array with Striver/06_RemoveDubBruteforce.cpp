#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
int bruteForeceDubRemover(vector<int> &a, int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    int index = 0;
    for (auto it : st)
    {
        a[index] = it;
        index++;
    }
    return index;
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
    cout << "Unique Elements is: " << bruteForeceDubRemover(a, n);
    return 0;
}