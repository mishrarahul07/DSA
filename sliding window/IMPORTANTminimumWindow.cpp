// MINIMUM WINDOW SUBSTRING
//Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

#include<bits/stdc++.h> 
#include<unordered_map>
using namespace std;

string minSubstring(string s, string t)
{
    string ans="";
    unordered_map<char, int> m;
    for(int i=0;i<t.length();i++)
    m[t[i]]++;
    int count=m.size();
    int i=0,j=0;
    while(j<s.length())
    {
        auto it=m.find(s[j]);
        if(it!=m.end()){
        m[s[j]]--;
        if(m[s[j]]==0)
        count--;}

        if(count>0)
        {
            j++;
        }
        else if(count==0)
        {
            while(count==0)
            {
            auto it=m.find(s[i]);
            if(it!=m.end())
            {
                m[s[i]]++;
                if(m[s[i]]==1)
                {
                count++;
                }
            }
            i++;
            }
            if(count==1)
            {
                if(ans.length()==0 || (ans.length()!=0 && ans.length()>j-i+2)){
                    ans="";
                for(int start=i-1;start<=j;start++)
                ans+=s[start];
            }}
            j++;
        }
    }
    return ans;
}

int main()
{
    string s,t;
    cin>>s>>t;
    string ans=minSubstring(s,t);
    cout<<ans;
    return 0;
}