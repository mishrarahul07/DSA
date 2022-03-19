#include<bits/stdc++.h>
using namespace std;

void reverse(string &s)
{
    if(s.length()==0||s.length()==1)
    return;
    
    char temp=s[s.length()-1];
    s.pop_back();
    reverse(s);
    s=temp+s;
    return;
}


int main()
{
    string s;
    cin>>s;
    reverse(s);
    cout<<s<<endl;
    return 0;
}