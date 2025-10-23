#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

//this solution is for if the Array has same number of positive and negative number... if the array have seperate i.e., n number of positve and negative != n that we use other algorithm which we discussed in 31

vector<int> rearrangeArrayByPosititveAndNegative(vector<int> &a, int n)
{
    vector<int> ans(n);
    int positive = 0, negative = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            ans[negative] = a[i];
            negative += 2;
        }
        else
        {
            ans[positive] = a[i];
            positive += 2;
        }
    }
    return ans;
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
    vector<int> array = rearrangeArrayByPosititveAndNegative(a, n);
    for (auto it : array)
    {
        cout << it<<" ";
    }
    return 0;
}