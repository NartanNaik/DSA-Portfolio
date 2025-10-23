#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (a[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}
void quickSort(vector<int> &a, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int part = partition(a, low, high);
    quickSort(a, low, part - 1);
    quickSort(a, part + 1, high);
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
    int sizeOfArray;
    cout << "Enter the size of the Array: ";
    cin >> sizeOfArray;
    vector<int> array(sizeOfArray);
    cout << "Enter the Array: " << endl;
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> array[i];
    }
    cout << "Before Array Sorted: ";
    printArray(array, sizeOfArray);
    quickSort(array, 0, sizeOfArray - 1);
    cout << "\nAfter Array Sorted: ";
    printArray(array, sizeOfArray);
    return 0;
}