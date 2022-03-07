// For input:
// 7 
// 4 1 1 1 2 3 5
//5
// your output is: 
// 4

/* ********************************************
CASE: Input: [1]
k: 0
OUTPUT: 0(No such subarray exists)
int subarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        int sum=0,count=0;
        while(j<nums.size()){
            sum+=nums[j];
            
            if(sum<k){
                j++;
            }
           
            else if(sum==k){
                count++;
                j++;
            }
            else if(sum>k){
                while(sum>k && i<=j){
                    sum-=nums[i];
                    i++;
                }
                if(i<=j)
                    sum-=nums[j];
                else j++;
    }
        }
        return count;
    }


**********************************************/

#include<bits/stdc++.h>
using namespace std;

vector<int> subarraysum(int arr[], int n, int s)
{
    vector<int> ans;
    int i=0,j=0;
    int sum=0;
    while(j<n)
    {
        sum+=arr[j];
        if(sum<s)
        j++;

        else if(sum==s)
        {
            ans.push_back(j-i+1);
            j++;
        }

        else if(sum>s)
        {
            while(sum>s)
            {
                sum-=arr[i];
                i++;
            }
            sum-=arr[j];
            
        }
    }
    return ans;
}


int main()
{
    int N,S;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++)
    cin>>A[i];
    cin>>S;
    vector<int>v= subarraysum(A,N,S);

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    cout<<*max_element(v.begin(),v.end());
    return 0;
}