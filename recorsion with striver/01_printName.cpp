#include <iostream>
#include <string>
using namespace std;

int num = 1;
void printName(int n, string name)
{
    if (num > n)
    {
        return;
    }
    cout << name << endl;
    num++;
    printName(n, name);
}

int main()
{
    string name;
    int n;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter count: ";
    cin >> n;
    printName(n, name);
    return 0;
}