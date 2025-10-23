#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
void sortArrayWhichContain0s1s2s(vector<int> &a, int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count0++;
        }
        else if (a[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    for (int i = 0; i < count0; i++)
    {
        a[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        a[i] = 1;
    }
    for (int i = count0 + count1; i < n; i++)
    {
        a[i] = 2;
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
    cout << "Array Before Sort: \n";
    printArray(a, n);
    sortArrayWhichContain0s1s2s(a, n);
    cout << "\nArray After solved by optimal Solution: \n";
    printArray(a, n);
    return 0;
}