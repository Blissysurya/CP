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
            string s;
            cin>>s;
            bool rock=false;
            int idx=0;
            for(int i=0;i<n-1;i++){
                if(s[i]=='p'){
                    rock=true;
                    idx=i;
                    break;
                }
            }
            if(n>=4){
                bool p=false;
                bool ss=false;
            for(int i=0;i<n;i++){
                if(s[i]=='p'){
                    p=true;
                }
                if(s[i]=='s'){
                    ss=true;
                }
            }

            if(p && ss){    
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
            }else{
                    cout<<"YES"<<endl;
            }
           
        }      
    }
