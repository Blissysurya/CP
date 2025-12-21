#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int repeated=0;
        for(int i=2;i<n;i++){
            if(s[i]==s[i-2]){
                repeated++;
            }
        }
        cout<<n-1-repeated<<endl;
    }
}