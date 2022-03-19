#include<bits/stdc++.h>
using namespace std;

void delete_middle(stack<int> &s,int k)
{
    if(s.size()==0)
    return ;
    if(k==1)
    {
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    delete_middle(s,k-1);
    s.push(temp);
}


int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    int middle_element=(s.size()/2)+1;
    delete_middle(s,middle_element);
    
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}