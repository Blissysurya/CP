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
struct compare{
    bool operator()(const int &lhs, const int&rhs)const{
        return lhs<rhs;
    }
};
istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int m,a,b,c;
        cin>>m>>a>>b>>c;

        int remseats1=0;
        int remseats2=0;
        int ans=0;
        if(a<=m){
            ans+=a;
            remseats1=m-a;
        }else{
            ans+=m;
            a-=m;
        }

        if(b<=m){
            ans+=b;
            remseats2=m-b;
        }else{
            ans+=m;
            b-=m;
        }
        int pool=remseats1+remseats2;

        if(pool==0){
            cout<<ans<<endl;
        }else{
            if(c<=pool){
                ans+=c;
            }
            else{
                ans+=pool;
            }

            cout<<ans<<endl;
        }
    
    }
}