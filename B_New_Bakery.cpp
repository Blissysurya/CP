#include <bits/stdc++.h>

using namespace std;

int f(int k,int a,int b,int n){
    int ans;
    for(int i=1;i<=k;i++){
        ans+=(b-i+1);
    }
    ans+=(n-k)*a;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int low=1;
        int high=n;

        int ans=a*n;
       while(high-low>3){
            int m1=low+(high-low)/3;
            int m2=high-(high-low)/3;
            if(f(m1,a,b,n)> f(m2,a,b,n)){
                high=m2;
            }else{
                low=m1;
            }
            cout<<f(low,a,b,n);
       }
       cout<<endl;
       }}