// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 0 5 10
// Explanation: for, orf and ofr appears
// in the txt, hence answer is index of first alphabet.

#include <bits/stdc++.h>
//#include<unordered_map>
using namespace std;

class Solution{
public:
	vector<int> search(string pat, string txt) {
	    // code here
	    vector<int> ans;
	    int i=0,j=0;
	    int k=pat.length();
	    int count;
	    map<char,int> m;
	    for(int l=0;l<k;l++)
	    m[pat[l]]++;
	    count=m.size();
	    while(j<txt.length())
	    {
	        auto it=m.find(txt[j]);
	        if(it!=m.end())
	        {
	            m[txt[j]]--;
	            if(m[txt[j]]==0)
	            count--;
	        }
	        if(j-i+1<k)
	        j++;
	        else if(j-i+1==k)
	        {
	            if(count==0)
	            ans.push_back(i);
	            
	            auto it=m.find(txt[i]);
	            if(it!=m.end())
	            {
	                m[txt[i]]++;
	                if(m[txt[i]]==1)
	                count++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}

};

int main()
{
    string pat,txt;
    cin>>txt>>pat;
    Solution ob;
    vector<int>v=ob.search(pat,txt);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
