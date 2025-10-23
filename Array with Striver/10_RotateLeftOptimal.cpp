#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;
void Reverse(vector<int> &a, int start, int end)
{
    while (start <= end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}// i wrote it just to to practice this is not used in the program.
void rotateOptimal(vector<int> &a, int n, int d)
{
    d %= n;
    if (d == 0 || n == 0)
        return;
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
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
    int d;
    cout << "Enter d: ";
    cin >> d;
    rotateOptimal(a, n, d);
    for (auto it : a)
    {
        cout << it << " ";
    }
    return 0;
}