#include <iostream>
using namespace std;
void print13(int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i+1; j++)
        {
            cout << count << " ";
            count++;
        }

        cout << endl;
    }
}
int main()
{
    int n, t;
    cout << "Enter the number how many time to test: ";
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cout << "Enter the number: ";
        cin >> n;
        print13(n);
    }

    return 0;
}