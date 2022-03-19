//Maximum Rectangular Area in a Histogram
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12

#include<bits/stdc++.h>
using namespace std;

vector<int> nearestsmallindexleft(long long arr[], int n)
    {
        stack<pair<long long,int> > s;
        vector<int> left;
        int pseudo_index=-1;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            left.push_back(pseudo_index);
            
            else if(!s.empty() && s.top().first<arr[i])
            left.push_back(s.top().second);
            
            else if(!s.empty() && s.top().first>=arr[i])
            {
                while(!s.empty() && s.top().first>=arr[i])
                s.pop();
                
                if(s.empty())
                left.push_back(pseudo_index);
                else
                left.push_back(s.top().second);
            }
            s.push(make_pair(arr[i],i));
        }
        while(!s.empty())
        s.pop();
        return left;
    }
    
    vector<int> nearestsmallindexright(long long arr[],int n)
    {
        stack<pair<long long,int> > s;
        vector<int> right;
        int pseudo_index=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            right.push_back(pseudo_index);
            
            else if(!s.empty() && s.top().first<arr[i])
            right.push_back(s.top().second);
            
            else if(!s.empty() && s.top().first>=arr[i])
            {
                while(!s.empty() && s.top().first>=arr[i])
                s.pop();
                
                if(s.empty())
                right.push_back(pseudo_index);
                else
                right.push_back(s.top().second);
            }
            s.push(make_pair(arr[i],i));
        }
        reverse(right.begin(),right.end());
        return right;
    }
    
    
int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    vector<int> left=nearestsmallindexleft(arr,n);
    vector<int> right=nearestsmallindexright(arr,n);
    //vector<int> width;
    long long area,mx_area=INT_MIN;
    for(int i=0;i<n;i++)
    {
        area=arr[i]*(right[i]-left[i]-1);
        cout<<area<<" ";
        mx_area=max(mx_area,area);
        //cout<<width[i]<<" ";
    }
    cout<<endl<<mx_area;

    // for(int i=0;i<n;i++)
    // cout<<width[i]<<" ";
    return 0;
}