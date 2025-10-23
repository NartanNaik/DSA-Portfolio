#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
int largestElement(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
int secondLargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
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
    int largest = largestElement(array, sizeOfArray);
    cout << "Largest Element is: " << largest;
    return 0;
}