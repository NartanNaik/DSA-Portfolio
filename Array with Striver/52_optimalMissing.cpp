#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// TC -> O(N)
// SC -> O(1)

vector<int> findMissingRepeating(vector<int> &a, long long n)
{
  long long SN = (n * (n + 1)) / 2;
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
  long long S = 0, S2 = 0;
  for (int i = 0; i < n; i++)
  {
    S += a[i];
    S2 += (long long)a[i] * (long long)a[i];
  }
  long long val1 = S - SN;
  long long val2 = S2 - S2N;
  val2 = val2 / val1;
  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};
}

int main()
{
  long long n;
  cout << "Enter the size of the Array: ";
  cin >> n;
  vector<int> a(n);
  cout << "Enter the Array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> ans = findMissingRepeating(a, n);

  cout << "The repeating is: " << ans[0] << " and The missing is: " << ans[1];

  return 0;
}