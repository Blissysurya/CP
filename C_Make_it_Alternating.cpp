
#include <bits/stdc++.h>
#include <numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
const int mod=998244353;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
int gcd(int a, int b)
{
    if(a>b) swap(a,b);
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

const long long MOD = 1e9 + 7;
vector<long long> fact;

void computeFactorials(int N) {
    fact.resize(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}


int32_t main(){

    computeFactorials(200000);
    int t;
    cin>>t;


    while(t--){
        string s;
        cin>>s;

        vector<int> bunches;

        int n = s.size();
        int cnt=1;

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }else{
                if(cnt!=1){
                    bunches.push_back(cnt);
                }
                cnt=1;
            }
        }

        if(cnt!=1){
            bunches.push_back(cnt);
        }

        int ans1=0;

        for(int i=0;i<bunches.size();i++){
            ans1 += bunches[i] -1 ;
        }

        int ans2=1;

        for(int i=0;i<bunches.size();i++){
            ans2 = ans2* fact[bunches[i]];
        }

        cout<<ans1<<" "<<ans2<<endl;

        }
    }
