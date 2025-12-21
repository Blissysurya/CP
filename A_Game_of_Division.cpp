#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       vi a(n,0);
       for (size_t i = 0; i < n; i++)
       {
        cin>>a[i];
       }
       int ans=0;
       bool pick=false;
       for (size_t i = 0; i < n; i++)
       {
        bool check=true;
        for (size_t j = 0; j < n; j++)
        {
            if(j!=i){
            if(abs(a[i]-a[j])%k==0){
                check=false;
                continue;
            }}
        }
        if(check){
            ans=i+1;
            pick=true;
            break;
        }
       }
       
       if(pick){
        cout<<"YES"<<endl;
        cout<<ans<<endl;
       }
       else{
        cout<<"NO"<<endl;
       }
       
    }
}