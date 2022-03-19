#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &v, int temp)
{
    if(v.size()==0)
    {
        v.push_back(temp);
        return;
    }
    
    int ele=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(ele);
    return;
}


void reverse(vector<int> &v)
{
    if(v.size()==0||v.size()==1)
    return;
    
    int temp=v[v.size()-1];
    v.pop_back();
    reverse(v);
    insert(v,temp);
    return;
}

int main()
{
    vector<int>v={1,2,3,4,5,6};
    reverse(v);
    for(auto i:v)
    cout<<i<<" ";
    return 0;
}