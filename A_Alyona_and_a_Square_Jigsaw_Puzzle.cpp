#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        int ans=1;
        int j=1;
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=vec[i];
            while(sum >= 2*(2*j+2)){
                if(sum== 2*(2*j+2)){
                    ans++;
                }
                sum-=2*(2*j+2);
                j+=2;
            }
        }
        cout<<ans<<endl;
    }
}