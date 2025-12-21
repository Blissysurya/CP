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
        int c=0;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(i+1);
        }
        for(int i=n-1;i>=0;i--){
            if(c>=i){
                break;
            }else{
            if(s[i]=='1'){
                ans-=(i+1);
                c++;
            }else{
                c--;
                if(c<0){
                    c=0;
                }
            }
            }
        }
        cout<<ans<<endl;
    }
}