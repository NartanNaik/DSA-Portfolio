#include <iostream>
using namespace std;
void countChar(string s)
{
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]-'a']++;
    }
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--)
    {
        char ch;
        cout << "Enter the Char: ";
        cin >> ch;
        cout << hash[ch - 'a'] << "\n";
    }
}
int main()  
{
    string s;
    cout << "Enter the Lower String: ";
    cin >> s;
    countChar(s);
    return 0;
}   