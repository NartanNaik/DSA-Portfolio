#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
int optimalLongest(vector<int> &a, int n)
{
  if (n == 0)
  {
    return 0;
  }
  int longest = 1;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(a[i]);
  }
  for (auto it : st)
  {
    if (st.find(it - 1) == st.end())
    {
      int count = 1;
      int x = it;
      while (st.find(x + 1) != st.end())
      {
        x += 1;
        count++;
      }
      longest = max(longest, count);
    }
  }
  return longest;
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
  int ans = optimalLongest(a,n);
  cout<<"The longest consequtive is: "<<ans;
  return 0;
}