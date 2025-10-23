#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
    // Time complexity of this is TC=O(2^n) almost not exactly it's exponantial in nature



    // if (n == 0 || n == 1)
    // {
    //     return n;
    // }
    // int prev2 = 0;
    // int prev1 = 1;
    // int curr;
    // for (int i = 2; i <= n; i++)
    // {
    //     curr = prev1 + prev2;
    //     prev2 = prev1;
    //     prev1 = curr;
    // }
    // return curr;this is using forloop and that is using recursion
}
int main()
{
    int n;
    cout << "Enter the term: ";
    cin >> n;
    cout << fibonacci(n);
    return 0;
}