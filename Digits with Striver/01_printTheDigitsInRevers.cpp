#include <iostream>
using namespace std;
int reversed(int n){
    int digit,reverse=0;
    while (n!=0)
    {
        digit=n%10;
        reverse=reverse*10+digit;
        n=n/10;
    }
    return reverse;
}
int main(){
    int n;
    cout<<"Give the number: ";
    cin>>n;
    int numb=reversed(n);
    cout<<"Reversed number: "<<numb;
    return 0;
}