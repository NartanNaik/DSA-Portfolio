#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
vector<vector<int>> setZerosByOptimal(vector<vector<int>> &matrix, int n, int m)
{
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
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
    cout << "Enter the elements to the Matrix: \n";
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }
    cout << "Matrix Before Calculation:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
        cout << "\n";
    }

    vector<vector<int>> updated = setZerosByOptimal(matrix, n, m);
    cout << "After Set: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}