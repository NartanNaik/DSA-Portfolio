#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
vector<int> intersectionWithBrute(vector<int> &a, vector<int> &a2)
{
    int n = a.size();
    int n2 = a2.size();
    vector<int> ans;
    vector<bool> visited(n2, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == a2[j] && !visited[j])
            {
                ans.push_back(a[i]);
                visited[j] = true;
                break;
            }
            if (a2[j] > a[i])
            {
                break;
            }
        }
    }
    return ans;
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
    cout << "Enter the size of the Array: ";
    cin >> n2;
    vector<int> a2(n2);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }
    auto answer = intersectionWithBrute(a, a2);
    cout << "Array after intersection: \n";
    for (auto it : answer)
    {
        cout << it << " ";
    }
    return 0;
}