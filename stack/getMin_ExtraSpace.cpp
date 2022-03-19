#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> s;
stack<int> ss;

void push(int x)
{
    if(s.empty())
    {
        s.push(x);
        ss.push(x);
    }
    else if(ss.top()<x)
    {
        s.push(x);
    }
    else if(ss.top()>=x)
    {
        s.push(x);
        ss.push(x);
    }
    return ;
}

int pop()
{
    if(s.empty())
    return -1;

    else if(s.top()==ss.top())
    {
        int ele=s.top();
        s.pop();
        ss.pop();
        return ele;
    }
     else //if(s.top()!=ss.top())
    {
        int ele=s.top();
        s.pop();
        return ele;
    }
}

int getMin()
{
    if(ss.empty())
    return -1;
    else
    return ss.top();
}


int main()
{
    push(2);
    push(3);
    cout<<pop()<<" ";
    cout<<getMin()<<" ";
    push(1);
    cout<<pop()<<" ";
    cout<<getMin()<<" ";
    return 0;
}