#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// #define int long long 
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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi vec(n);

        cin>>vec;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int m=vec[i];
            int z=2;
            while(z*z<=m){
                if(m%z==0){
                    mp[z]++;
                    m/=z;
                }else{
                    z++;
                }
            }
            if(m>1){
                mp[m]++;
            }
        }

        bool rock=true;

        for(auto it: mp){
            if(it.second%n!=0){
                rock=false;
                break;
            }
        }

        if(rock){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


        }      
    }
