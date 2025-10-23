#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool palindrome(int l, string &s)
{
    if (l >= s.size() / 2)
    {
        return true;
    }
    if (s[l] != s[s.size() - l - 1])
    {
        return false;
    }
    return palindrome(l + 1, s);
}

int main()
{
    string s;
    cout << "Enter Name: ";
    cin >> s;

    cout << palindrome(0, s);

    return 0;
}