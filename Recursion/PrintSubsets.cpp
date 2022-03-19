#include <iostream>

using namespace std;

void solve(string in, string out)
{
    if(in.length()==0)
    {
        cout<<out<<" ";
        return;
    }
    
    
    string out1=out;
    string out2=out;
    out2.push_back(in[0]);
    in.erase(in.begin()+0);
    
    solve(in,out1);
    solve(in,out2);
    return;
}

int main()
{
    string input,output="";
    cin>>input;
    solve(input,output);

    return 0;
}
