
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

int ternary_search(int lo, int hi) {
    while (hi - lo >= 3)
    {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        // int f1 = f(mid1);
        // int f2 = f(mid2);
        // if (f1 > f2)
        // {
        //     hi = mid2;
        // }
        // else if (f1 < f2)
        // {
        //     lo = mid1;
        // }
        // else
        // {
        //     // Note: this case doesn’t need to be explicitly handled
        //     lo = mid1;
        //     hi = mid2;
        // }
    }
    int ans = INT_MIN;
    
    // for (int i = lo; i <= hi; i++) ans = max(ans, f(i));
   
    return ans;
}

int bitstring_tonum(string s){
    int n=s.size();
    int num=0;
    for(int i=0;i<n;i++){
       if(s[i]=='1'){
        num=2*num+1;
       }else{
        num=2*num;
       }
    }

    return num;
}

string num_to_str(int x){
    string ans;
    while(x>0){
        if(x%2==1){
            ans+="1";
        }else{
            ans+="0";
        }
        x/=2;
    }
    reverse(whole(ans));

    return ans;
}

string xxor(string a, string b){
    string c;
    int n=a.size();
    for(int i=0;i<n;i++){
        char x=a[i];
        char y=b[i];
        if((x-'0')^(y-'0')==1){
            c+="1";
        }else if((x-'0')^(y-'0')==0){
            c+="0";
        }
    }

    return c;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        string s1;
        string s2;
        cin>>s1>>s2;

        // int num1=bitstring_tonum(s1);
        // int num2=bitstring_tonum(s2);

        // int x=num1^num2;
        // string xs=num_to_str(x);
        string xs=xxor(s1,s2);
        vector<int> pos;


        // if(xs[0]=='1'){
        //     pos.push_back(0);
        // }
        for(int i=1;i<n;i++){
            if(xs[i]!=xs[i-1]){
                pos.push_back(i-1);
            }
        }

        if(xs[n-1]=='1'){
            pos.push_back(n-1);
        }
        vector<int> zeroes(n,0);
        vector<int> ones(n,0);

        for(int i=0;i<n;i++){
            if(s1[i]=='0'){
                zeroes[i]++;
            }
        }

        for(int i=1;i<n;i++){
            zeroes[i]+=zeroes[i-1];
        }


        for(int i=0;i<n;i++){
            if(s1[i]=='1'){
                ones[i]++;
            }
        }

        for(int i=1;i<n;i++){
            ones[i]+=ones[i-1];
        }
        bool poss=true;

        // for(int i=0;i<n;i++){
        //     cout<<ones[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<zeroes[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<pos.size();i++){
        //     cout<<pos[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<pos.size();i++){
            if(zeroes[pos[i]]!=ones[pos[i]]){
                cout<<"NO"<<endl;
                poss=false;
                break;
            }
        }
        
        if(poss){
            cout<<"YES"<<endl;
        }
        // }
    }
}