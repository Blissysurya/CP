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
       int n;
       cin>>n;
       vi vec(n,0);
       for (size_t i = 0; i < n; i++)
       {
        cin>>vec[i];
       }
       sort(whole(vec));
       
       

    }
}