#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;
string twoSumWithBetter(vector<int> &book, int target, int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = book[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end())
        {
            return "Yes"; // return {mpp[more], i} <- if we have to return index
        }
        mpp[a] = i;
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
    int k;
    cout<<"Enter the k: ";
    cin>>k;
    cout<<twoSumWithBetter(a,k,n);
    return 0;
}