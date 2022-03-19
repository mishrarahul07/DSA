#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int temp)
{
    if(s.empty() || s.top()<=temp)
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

void sort_stack(stack<int> &s)
{
    if(s.empty() || s.size()==1)
    return;
    
    int temp=s.top();
    s.pop();
    sort_stack(s);
    insert(s,temp);
    return;
}



int main()
{
    stack<int>s;
    s.push(7);
    s.push(3);
    s.push(5);
    s.push(4);
    sort_stack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}