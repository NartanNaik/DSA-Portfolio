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

    bool canWePlace(vector<int> &a, int dist, int cows)
    {
        int cntCows = 1, last = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] - last >= dist)
            {
                cntCows++;
                last = a[i];
            }
            if (cntCows >= cows)
            {
                return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        int low = 1, high = a[n - 1] - a[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canWePlace(a, mid, k) == true)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
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
        int cows;
        cout << "Enter the number of cows: ";
        cin >> cows;
        int ans = aggressiveCows(a, cows);
        cout << "The minimum max is: " << ans;
        return 0;
    }