// Max Area Rectangle in binary matrix
// Given a binary matrix, find the maximum size rectangle binary-sub-matrix 
// with all 1’s.

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> NSLindex(vector<int> v)
  {
      vector<int> left;
      stack< pair<int,int> > s;
      int pseudo_index=-1;
      for(int i=0;i<=v.size();i++)
      {
          if(s.empty())
         left.push_back(pseudo_index);
          
          else if(!s.empty() && s.top().first<v[i])
          left.push_back(s.top().second);
          
          else if(!s.empty() && s.top().first>=v[i])
          {
              while(!s.empty() && s.top().first>=v[i])
              s.pop();
              
              if(s.empty())
              left.push_back(pseudo_index);
              else
              left.push_back(s.top().second);
          }
          
          s.push(make_pair(v[i],i));
      }
      return left;
  }

  
  vector<int> NSRindex(vector<int> v)
  {
      vector<int> right;
      stack< pair<int,int> > s;
      int pseudo_index=v.size();
      for(int i=v.size()-1;i>=0;i--)
      {
          if(s.empty())
          right.push_back(pseudo_index);
          
          else if(!s.empty() && s.top().first<v[i])
          right.push_back(s.top().second);
          
          else if(!s.empty() && s.top().first>=v[i])
          {
              while(!s.empty() && s.top().first>=v[i])
              s.pop();
              
              if(s.empty())
              right.push_back(pseudo_index);
              else
              right.push_back(s.top().second);
          }
          
          s.push(make_pair(v[i],i));
      }
      reverse(right.begin(),right.end());
      return right;
  }
  
  int MAH(vector<int> v)
  {
      vector<int> right=NSRindex(v);
      vector<int> left=NSLindex(v);
      int area,mx=INT_MIN;
      for(int i=0;i<v.size();i++)
      {
          area=v[i]*(right[i]-left[i]-1);
          mx=max(mx,area);
      }
      return mx;
  }
  
  
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> Hist;
        for(int j=0;j<m;j++)
        Hist.push_back(M[0][j]);
        
        int mx,area;
        mx=MAH(Hist);
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (M[i][j]==0)
                Hist[j]=0;
                else
                Hist[j]+=M[i][j];
            }  
                area=MAH(Hist);
                mx=max(mx,area);
            
        }
        return mx;
    }




  int main()
  {
      int m,n;
      cin>>n>>m;
      int M[MAX][MAX];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        cin>>M[i][j];
      }

      int mx=maxArea(M,n,m);
      cout<<mx;
      return 0;
      
  }