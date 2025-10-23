#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string in lower case: ";
    cin >> s;
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }
    int q;
    cout << "Enter the query time: ";
    cin >> q;
    while (q--)
    {
        char ch;
        cout << "Enter the char: ";
        cin >> ch;
        cout << mpp[ch] << endl;
    }
    cout << "Iteration of the unordered map";
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    return 0;
}