#include <bits/stdc++.h>
#include <numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
#define ll long long
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

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


long long binpow(long long a, long long b, long long mod) {
    long long res = 1;
   a=a%mod;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = (a * a) % mod;
       
        b >>= 1;
    }
    return res;
}

vector<int> least_prime(MAXV, 0);
void leastPrimeFactor(int n)
{
    least_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
       
        if (least_prime[i] == 0)
        {
           
            least_prime[i] = i;
 
            for (int j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }
}
 vector<bool> prime(MAXV, true);
void Sieve(int n)
{
  for (int p = 2; p * p <= n; p++) {

        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int mostSignificantBit(int n) {
    int msb = 0;
    while (n >>= 1) {
        msb++;
    }
    return 1 << msb;
}

int leastSignificantBit(int n) {
    return n & -n;
}

bool isIthBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

int rhash(string s){
    int MOD=1e9+7;
    int h=0;
    int p=1;

    for(int i=0;i<s.size();i++){
        h=(h+((s[i]-'a'+1)*p)%MOD)%MOD;
        p=(p*31ll)%MOD;
    }

    return h;
}



    int rollinghash(string s, int x) {
    int MOD = 1e9 + 7;
    string t = s.substr(0, x);
    int n = s.size();
    int hash_t = rhash(t);
    int hash_s = rhash(s.substr(0, x));

    int count = 0;
    if(hash_t == hash_s) {
        count++;
    }
    // cout<<count<<endl;

    // int p = 1;
    // for(int i = 1; i < x; i++) {
    //     p = (p * 31) % MOD;
    // }

    int pL=1;
    int pR=binpow(31,x,MOD);
    for(int i=x;i<n;i++) {
        hash_s=(hash_s-((s[i-x]-'a'+1)*pL)%MOD + MOD)%MOD;
        hash_s=(hash_s+((s[i]-'a'+1)*pR)%MOD)%MOD;
        hash_t=(hash_t*31)%MOD;
        if(hash_t == hash_s) {
            count++;
        }
        pR=(pR*31)%MOD;
        pL=(pL*31)%MOD;

    }

    return count;



}

void solve (string s){
    int n=s.size();
    vector<int> prehash(n,0);
    int base=31;
    int MOD=1e9+7;
    prehash[0]=(s[0]-'a'+1);
    int p=31;
    for(int i=1;i<n;i++){
       prehash[i]=(prehash[i-1]+((s[i]-'a'+1)*p)%MOD)%MOD;
       p=(p*31ll)%MOD;
    }

    vector<int> ans;
    int hash=0;
    for(int i=n-1;i>=0;i--){
       hash=(hash*31ll)%MOD;
       hash=(hash+(s[i]-'a'+1))%MOD;
       if(prehash[n-i-1]==hash){
            ans.push_back(n-i);
       }
    }

    
    // for(int i=0;i<n;i++){
    //     if(prehash[i]==sufhash[i]){
    //         ans.push_back(i+1);
    //     }
    // }

    int low=0;
    int high=ans.size()-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(rollinghash(s,ans[mid]) >=3 ){
            // cout<<"Hi"<<endl;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

       if(high<0){
        cout<<"Just a legend"<<endl;
       } else{
        cout<<s.substr(0,ans[high])<<endl;
       }

}

int32_t main(){
        string s;
        cin>>s;

        solve(s);

    }




