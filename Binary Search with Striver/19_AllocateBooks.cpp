#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int countStudents(vector<int> &a, int pages)
{
    int students = 1;
    long long pagesCount = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (pagesCount + a[i] <= pages)
        {
            pagesCount += a[i];
        }
        else
        {
            students++;
            pagesCount = a[i];
        }
    }
    students;
}

int findStudents(vector<int> &a, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(a, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
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
    int m;
    cout << "Enter the number of Students: ";
    cin >> m;
    int ans = findStudents(a, n, m);
    cout << "The minimum pages you can assign to the student " << m << " is : " << ans;
    return 0;
}