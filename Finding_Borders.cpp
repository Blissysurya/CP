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

long long modulo_inverse(long long base,long long mod){
    return binpow(base,mod-2,mod);
}

// void solve(string s){
//     int n=s.size();
//     long long mod1=1e9+7;
//     long long mod2=1e9+9;
//     long long base1=31;
//     long long base2=37;

//     vector<long long> hash1(n,0);
//     vector<long long> hash2(n,0);
//     hash1[0]=hash2[0]=(s[0]-'a'+1);
//     for(int i=1;i<n;i++){
//         hash1[i]=(hash1[i-1]+(s[i]-'a'+1)*binpow(base1,i,mod1))%mod1;
//         hash2[i]=(hash2[i-1]+(s[i]-'a'+1)*binpow(base2,i,mod2))%mod2;
//     }
//     cout<<"YES";
//     for(int len=1;len<n;len++){
//         cout<<"Hi";
//         long long hash1prefix=hash1[len-1];
//         long long hash2prefix=hash2[len-1];

//         long long hash1suffix=((hash1[n-1]-hash1[n-len-1]+mod1)%mod1*modulo_inverse(binpow(base1,n-len,mod1),mod1)%mod1)%mod1;
//         long long hash2suffix=((hash2[n-1]-hash2[n-len-1]+mod2)%mod2*modulo_inverse(binpow(base2,n-len,mod2),mod2)%mod2)%mod2;
//         cout<<hash1prefix<<" "<<hash1suffix<<endl;
//         if(hash1prefix==hash1suffix && hash2prefix==hash2suffix){
//             cout<<len<<" ";
//         }
//     }
// }

// void solve(string s) {
//     int n = s.size();
//     long long mod1 = 1e9 + 7;
//     long long mod2 = 1e9 + 9;
//     long long base1 = 31;
//     long long base2 = 37;

//     vector<long long> hash1(n, 0);
//     vector<long long> hash2(n, 0);
//     hash1[0] = hash2[0] = (s[0] - 'a' + 1);
//     for (int i = 1; i < n; i++) {
//         hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * binpow(base1, i, mod1)) % mod1;
//         hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * binpow(base2, i, mod2)) % mod2;
//     }

//     cout << "YES" << endl;
//     for (int len = 1; len < n; len++) {
//         cout << "Hi" << endl;
//         long long hash1prefix = hash1[len - 1];
//         long long hash2prefix = hash2[len - 1];

//         long long hash1suffix = ((hash1[n - 1] - hash1[n - len - 1] + mod1) % mod1 
//                                 * modulo_inverse(binpow(base1, n - len, mod1), mod1)) % mod1;
//         long long hash2suffix = ((hash2[n - 1] - hash2[n - len - 1] + mod2) % mod2 
//                                 * modulo_inverse(binpow(base2, n - len, mod2), mod2)) % mod2;
        
//         cout << hash1prefix << " " << hash1suffix << endl;
//         if (hash1prefix == hash1suffix && hash2prefix == hash2suffix) {
//             cout << len << " ";
//         }
//     }
// }

void solve(string s) {
    int n = s.size();
    long long mod1 = 1e9 + 7;
    long long mod2 = 1e9 + 9;
    long long base1 = 31;
    long long base2 = 37;

    vector<long long> hash1(n, 0);
    vector<long long> hash2(n, 0);
    hash1[0] = hash2[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
        hash1[i] = (hash1[i - 1] + (s[i] - 'a' + 1) * binpow(base1, i, mod1)) % mod1;
        hash2[i] = (hash2[i - 1] + (s[i] - 'a' + 1) * binpow(base2, i, mod2)) % mod2;
    }

    cout << "YES" << endl;
    for (int len = 1; len < n; len++) {
        cout << "Hi" << endl;
        long long hash1prefix = hash1[len - 1];
        long long hash2prefix = hash2[len - 1];

        long long hash1suffix = (hash1[n - 1] - hash1[n - len - 1] + mod1) % mod1;
        hash1suffix = (hash1suffix * modulo_inverse(binpow(base1, n - len, mod1), mod1)) % mod1;

        long long hash2suffix = (hash2[n - 1] - hash2[n - len - 1] + mod2) % mod2;
        hash2suffix = (hash2suffix * modulo_inverse(binpow(base2, n - len, mod2), mod2)) % mod2;
        
        cout << hash1prefix << " " << hash1suffix << endl;
        if (hash1prefix == hash1suffix && hash2prefix == hash2suffix) {
            cout << len << " ";
        }
    }
}



int32_t main(){
    string s;
    cin>>s;
    solve(s);
    }
