#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
void insertionSort(vector<int> &a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && a[j - 1] > a[j])
        {
            int temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
            j--;
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
    cout << "Array Before Print: ";
    printArray(a, n);
    cout << "\nArray After Print: ";
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}