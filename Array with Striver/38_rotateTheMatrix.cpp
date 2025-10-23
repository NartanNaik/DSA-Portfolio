#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n, m;
    cout << "Enter row: ";
    cin >> n;
    cout << "Enter column:";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elemets to the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    cout << "Matrix before rotation: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    rotateMatrix(matrix, n, m);
    cout << "Matrix Before rotation: \n";
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