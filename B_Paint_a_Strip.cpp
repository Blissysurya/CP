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

int rec(int n){
    if(n<=1){
        return 1;
    }
    return rec((n-1)/2)+1;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       cout<<rec(n)<<endl;
       
       

    }
}