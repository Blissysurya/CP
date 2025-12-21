#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
        int t;
        cin>>t;
        while(t--){
            int k;
            cin>>k;
            int high;

            for(int i=0;i<64;i++){
                int x=(int)sqrtl(1ll<<i);
                if((1ll<<i)-x >= k){
                    high=1ll<<i;
                    break;
                }
            }
            int low=1;
            int ans;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(mid-(int)sqrtl(mid) >= k){
                    ans=mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            cout<<ans<<endl;
        }
}