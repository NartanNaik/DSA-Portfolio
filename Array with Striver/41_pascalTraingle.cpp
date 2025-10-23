#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int i = 1; i < row; i++)
    {
        ans *= (row - i);
        ans /= i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTraingle(int n)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    vector<vector<int>> solution = pascalTraingle(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < solution[i].size(); j++)
        {
            cout << solution[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}