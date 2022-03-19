#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }
    
    int ele=s.top();
    s.pop();
    insert(s,temp);
    s.push(ele);
    return;
}

void reverse_stack(stack<int> &s)
{
    if(s.size()==0 || s.size()==1)
    return;
    
    int temp=s.top();
    s.pop();
    
    
    reverse_stack(s);
    insert(s,temp);
    return;
}


int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    
    reverse_stack(s);
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}