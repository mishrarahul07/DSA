/*King sandwich: 4 breads and 1 eggSlice
Regular sandwich: 2 breads and 1 eggSlice.
Return [total king, total regular] so that the
number of remaining breads equal to 0 and the
number of remaining eggSlice equal to 0. If it is
not possible to make the remaining breads and eggSlice
equal to 0 return [].
****Salesforce****
*/
#include<bits/stdc++.h>
using namespace std;

//Abhipsa's code
/*vector<int> NoWastage(int b,int es)
{
    vector<int> v;

    if(b % 2 != 0)
    return v;

    if(b < es*2)
    return v;

    if(b == es*2)
    {
        v.push_back(0);
        v.push_back(es);
        return v;
    }
    
    if(b % 4 ==0 && b == es*4)
    {
        v.push_back(es);
        v.push_back(0);
        return v;
    }

    int k=0;
    while(k<es)
    {
        if((b-4*k)/2==es-k)
        {
            v.push_back(k);
            v.push_back(es-k);
            return v;
        }
        k++;
    }
    return v;
}*/


//RG's code
/*vector<int> NoWastage(int b,int es)
{
    vector<int> v;
    int remfour=b%4;
    if((b%2!=0) || (es>b/2) || es<(b/4)+(remfour/2))
    return v;
    
    int multipletwo= b/2;
    
    int k= multipletwo-es;
    int r= es-k;
    v.push_back(k);
    v.push_back(r);
    return v;
    
}*/

//Rounak's code
vector<int> NoWastage(int b,int es)
{
    vector<int> v;
    if((b<2*es)||(b>4*es)||(b%2!=0))
    return v;
    
    int x,y;
    x=(b-2*es)/2;
    y=es-x;
    v.push_back(x);
    v.push_back(y);
    return v;
}

int main()
{
    int b,es;
    cin>>b>>es;
    vector<int> ans= NoWastage(b,es);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}