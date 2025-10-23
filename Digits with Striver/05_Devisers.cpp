// #include <iostream>
// using namespace std;
// void devisors(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             cout << i<<" ";
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     cout<<"Devisers: ";
//     devisors(n);
//     return 0;
// } time complexity of this is O(N)... so reduce the TC of this we do like below..

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void devisors(int n)
{
    vector<int> ls;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if ((n / i) != i)
            {
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for (auto it : ls)
    {
        cout << it << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Devisers: ";
    devisors(n);
    return 0;
}
