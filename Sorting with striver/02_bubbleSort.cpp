#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
void bubbleSort(vector<int> &a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
}
void printArray(vector<int> array, int number)
{
    for (int i = 0; i < number; i++)
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
    cout << "Enter the Array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Array Before Sort: \n";
    printArray(a, n);
    cout << "\nArray After Sort: \n";
    bubbleSort(a, n);
    printArray(a, n);
    return 0;
}