#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &a, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (a[j] <= a[min])
            {
                min = j;
            }
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Araray Before Sort: " << endl;
    printArray(a, n);
    cout << "\nAraray After Sort: " << endl;
    selectionSort(a, n);
    printArray(a, n);
    return 0;
}