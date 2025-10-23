#include<iostream>
using namespace std;
int palindrome(int n){
    int digit,reverse=0;
    int dub=n;
    while (n!=0)
    {
        digit = n%10;
        reverse = reverse*10+digit;
        n=n/10;
    }
    if (reverse==dub)
    {
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;
    cout<<"Give me a number: ";
    cin>>n;
    int b = palindrome(n);
    if (b==1)
    {
        cout<<"This is the Palindrome";
    }else
    {
        cout<<"This is not the Palindrome";
    }
    
    
    return 0;
}