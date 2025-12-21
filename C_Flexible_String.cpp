#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
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

int32_t main(){
    int t;
    cin>>t;
    // leastPrimeFactor(MAXV);
    while(t--){
            int n,k;
            cin>>n>>k;

            string s1,s2;

            cin>>s1>>s2;

            set<int> s;
            vi ans;
            int pick=0;
            for(int i=0;i<n;i++){
                if(s1[i]==s2[i]){
                    pick++;
                }
                else if(s1[i]!=s2[i]){
                    if(s.size()<k){
                        pick++;
                        s.insert(s1[i]);
                    }else{
                        if(s.find(s1[i])!=s.end()){
                            pick++;
                        }else{
                        if(pick!=0){
                            ans.push_back(pick);
                            pick=0;
                        }
                        }
                    }
                }
            }
            if(pick!=0){
                ans.push_back(pick);
            }

           

            // int result=0;
            // for(int i=0;i<ans.size();i++){
            //     result+=(ans[i]*(ans[i]+1))/2;
            // }

            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }

            cout<<endl;

            // cout<<result<<endl;;
        }      
    }
