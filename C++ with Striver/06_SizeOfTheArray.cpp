#include <iostream>
using namespace std;
int main()
{
    string str = "Nartan";
    int size = str.size();
    str[size-1]='E';
    cout << str[size - 1];
    return 0;
}