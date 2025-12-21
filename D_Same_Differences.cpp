#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        map<int,int> m;
        for (size_t i = 0; i < n; i++)
        {
           cin>>a[i];
        }
        for (size_t i = 0; i < n; i++)
        {
            m[a[i]-i]++;
        }
        int ans=0;
       for(auto it: m){
        
        ans+=(it.second*(it.second-1))/2;
       

       } 

       cout<<ans<<endl;
  
    }
}