#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

void optimalSolutionFor0s1s2s(vector<int> &a, int n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

void printArray(vector<int> array, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << array[i] << " ";
    }
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
    cout << "Array before Sort: \n";
    printArray(a, n);
    optimalSolutionFor0s1s2s(a, n);
    cout << "\nArray after Sort: \n";
    printArray(a, n);
    return 0;
}