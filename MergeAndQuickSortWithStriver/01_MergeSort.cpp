#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
void Merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &a, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    Merge(a, low, mid, high);
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
    cout << "Array before Sort: " << endl;
    printArray(array, sizeOfArray);
    mergeSort(array, 0, sizeOfArray - 1);
    cout << "\nArray After Sort: " << endl;
    printArray(array, sizeOfArray);
    return 0;
}