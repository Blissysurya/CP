#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a>=b){
            cout<<a<<endl;
            continue;
        }else{
            if(b-a > a){
                cout<<0<<endl;
                continue;
            }else{
                cout<<a-(b-a)<<endl;
                continue;
            }
        }
    }
}