#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

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
    int seclargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > seclargest && arr[i] != largest)
        {
            seclargest = arr[i];
        }
    }
    return seclargest;
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
    int secondLargestel = secondLargest(array, sizeOfArray);
    cout << "Second Largest Element is: " << secondLargestel;
    return 0;
}