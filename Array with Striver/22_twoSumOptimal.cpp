#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;
string twoSumWithOpatimal(vector<int> &book, int n, int target)
{
    int left = 0;
    int right = n - 1;
    sort(book.begin(), book.end());
    while (left < right)
    {
        int sum = book[left] + book[right];
        if (sum == target)
        {
            return "Yes";
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "No";
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
    int target;
    cout << "Enter the target: ";
    cin >> target;
    cout << twoSumWithOpatimal(a, n, target);
    return 0;
}