#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int KUnique(string s, int k)
{
    unordered_map<char, int> m;
    int i=0,j=0,mx=INT_MIN;

    while(j<s.length())
    {
        m[s[j]]++;

        if(m.size()<k)
        j++;

        else if(m.size()==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }

        else if(m.size()>k)
        {
            while(m.size()>k){
            m[s[i]]--;
            if(m[s[i]]==0)
            m.erase(s[i]);

            i++;}
            j++;
        }
    }
    return mx;
}

int main()
{
    string s;
    int k;
    cin>>s>>k;
    int ans= KUnique(s,k);
    cout<<ans;
    return 0;
}