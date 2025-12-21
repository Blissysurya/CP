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

        sort(vec.begin(),vec.end());

        vector<int> pre(n-1,0);
        for(int i=0;i<n-1;i++){
            pre[i]=vec[i]+vec[i+1];
        }

        int minel=INT_MAX;
       for(int i=0;i<n;i++){
            int ans=0;
            
            ans+=(int)(upper_bound(pre.begin(),pre.end(),vec[i])-pre.begin());
            
            ans+=n-i-1;
            minel=min(minel,ans);
        }
        cout<<minel<<endl;
    }
}