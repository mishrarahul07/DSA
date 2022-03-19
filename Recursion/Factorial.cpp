#include<bits/stdc++.h>
using namespace std;

int factorial_recursive(int n)
{
    int product;
    if(n==0||n==1)
    {
        return 1;
    }
    
    product=n*factorial_recursive(n-1);
    
    return product;
}

int main()
{
    int n;
    cin>>n;
    cout<<factorial_recursive(n);
    return 0;
}