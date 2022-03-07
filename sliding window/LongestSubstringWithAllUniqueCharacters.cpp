#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int AllUnique(string s)
{
    int i=0,j=0;
    int mx=INT_MIN;
    unordered_map<char,int> m;
    while(j<s.length())
    {
        m[s[j]]++;

        /*if(s1.size()<j-i+1)
        j++;*/

        if(m.size()==j-i+1)
        {
            mx=max(j-i+1,mx);
            j++;
        }

        else if(m.size()<j-i+1)
        {
            while(m.size()<j-i+1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    if(m.size()==j-i)
    mx=max(mx,j-i);
    return mx;
}


int main()
{
    string s;
    cin>>s;
    int ans= AllUnique(s);
    cout<<ans;
    return 0;
}