#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<vector<int>> setZerosBetter(vector<vector<int>> &matrix, int n, int m)
{
    vector<int> col(m, 0);
    vector<int> row(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
int main()
{
    int n, m;
    cout << "Enter row: ";
    cin >> n;
    cout << "Enter column: ";
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the Matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        cout << "\n";
    }

    cout << "Original Matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> updated = setZerosBetter(arr, m, n);

    cout << "Answer Matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << updated[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}