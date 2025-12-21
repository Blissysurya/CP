#include <bits/stdc++.h>
using namespace std;
#define int long long

int fast(int x, int y){
    int res=1;
    while(y>0){
        if(y&1){
            res=res*x;
        }

        y=y>>1;
        x=x*x;
    }
    return res;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
      
        int ans=0;
        if(k==1){
            cout<<n<<endl;
        }else{
        while(n>0){
            int power=1;
            while(fast(k,power) <= n){
                power++;
            }
            power--;

            n-=fast(k,power);
            ans++;
        }
        cout<<ans<<endl;
        }
    }
}
