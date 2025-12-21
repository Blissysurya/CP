#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int b;
        int c;
        cin>>n>>b>>c;
        int ans=0;
        if(n==b && b==c){
            cout<<n<<endl;
        }
        else if(n==1 && b==0 && c==0){
            cout<<0<<endl;
        }
        else if(n==1 ){
            cout<<1<<endl;
        }
        else if(b==0 && c==0){
            cout<<-1<<endl;
        }
        else if(b==0){
            cout<<n-c<<endl;
        }
        
        else{
            cout<<n-(n/b) <<endl;
        }
    }
}