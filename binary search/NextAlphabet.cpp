#include<bits/stdc++.h>
using namespace std;

//Aditya Verma's code
// char nextAlphabet(char arr[],int n, char key)
// {
//     char res='#';
//     int start=0,end=n-1;
//     while(start<=end)
//     {
//         int mid=start+(end-start)/2;
//         if(arr[mid]<=key)
//         start=mid+1;
//         else
//         {
//             res=arr[mid];
//             end=mid-1;
//         }
//     }
//     return res;
// }

char nextAlphabet(char arr[], int n, char key)
{
    // char res='#';
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]<=key)
        start=mid+1;
        else
        {
            //res=arr[mid];
            end=mid-1;
        }
    }
    //return res;
    if(start==n)
    return '#';
    else
    return arr[start];
}

int main()
{
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    char key;
    cin>>key;
    char ans=nextAlphabet(arr,n,key);
    cout<<ans;
    return 0;
}