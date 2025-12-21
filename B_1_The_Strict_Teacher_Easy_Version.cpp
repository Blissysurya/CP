#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        int a,b;
        cin>>a>>b;
        int x;
        cin>>x;
        if(b<a){
            swap(a,b);
        }
        if(a<x and b>x)
        {   
            
            {cout<<(b-a)/2<<endl;continue;}
            
        }
        if(x>b) {cout<<n-b<<endl;continue;}
        if(x<a) {cout<<a-1<<endl;continue;}
    }
 
    return 0;
}