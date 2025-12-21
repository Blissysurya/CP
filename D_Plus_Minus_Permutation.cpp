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
int func(int l,int r){
    return ((r-l+1)*(r+l))/2;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        
        int c1=0,c2=0;
        c1=n/x - n*gcd(x,y)/(x*y);
        c2=n/y - n*gcd(x,y)/(x*y);
      

        cout<<func(n-c1+1,n)-func(1,c2)<<endl;

    }
}