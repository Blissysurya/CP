#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
   
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
         vector<int> vec(n,0);
        vec[0]=0;
        int p=1;
        for(int i=n-1;i>=1;i--){
            vec[p]=(2*(s[i]-'0')-1);
            p++;
        }
    for(int i=1;i<n;i++){
        vec[i]+=vec[i-1];
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());

    int ans=-1;
    int sum=0;

    for(int j=2;j<=n+1;j++){
        sum+=vec[j-2];
        if(sum >=k ){
            ans=j;
            break;
        }
    }
    cout<<ans<<endl;
    
    }
}