// #include <iostream>
// using namespace std;
// int main()
// {
//     int a[5];
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "Enter Arra A[" << i << "]\n";
//         cin >> a[i];
//     }
//     cout << "Your Array:\n";
//     for (int j = 0; j < 5; j++)
//     {
//         cout << a[j] << " ";
//     }

//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}