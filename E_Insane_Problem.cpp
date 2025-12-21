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

int powerOptimised(int a, int n)
{
    int ans = 1;

    while (n > 0) {
        int last_bit = (n & 1);
        if (last_bit) {
            ans = ans * a;
        }

        a = a * a;
        n = n >> 1;
    }

    return ans;
}


long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int k,l1,r1,l2,r2;
        cin>>k>>l1>>r1>>l2>>r2;
        int ans=0;
        int count=0;
        for(int i=l1;i<=r1;i++){
            
            for(int j=1;j<30;j++){
                
                if(i*binpow(k,j)>=l2 && i*binpow(k,j)<=r2){
                        ans++;
                }
                if(i*binpow(k,j)>r2){
                    break;
                }
                count++;
            }
        }

        cout<<ans<<endl;
    
    }
}