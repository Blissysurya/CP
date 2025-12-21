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

int leastSignificantBit(int n) {
    return n & -n;
}

int mostSignificantBit(int n) {
    int msb = 0;
    while (n >>= 1) {
        msb++;
    }
    return 1 << msb;
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}


int32_t main(){
    // int t;
    // cin>>t;
    // leastPrimeFactor(MAXV);
    // while(t--){
            // int n,k;
            // cin>>n>>k;
            // vi a(n+1);
            // for(int i=1;i<n+1;i++){
            //     a[i]=i;
            // }
            // if(k%2==0){       
            //         k/=2;
            //         int x=n-1;
            //         for(int i=1;i<n+1;i++){

            //             if(k<=x){
            //                 swap(a[i],a[i+k]);
            //                 k=0;
            //                 break;
            //             }
            //             swap(a[i],a[i+x]);
            //             k-=x;
            //             x-=2;
            //             if(x<=0) break;
            //         }
            //         if(k>0){
            //             cout<<"NO"<<endl;
            //         }else{
            //         cout<<"YES"<<endl;
            //         for(int i=1;i<=n;i++){
            //             cout<<a[i]<<" ";
            //         }
            //         cout<<endl;
            //         }
            // }else{
            //     cout<<"NO"<<endl;
            // }


            cout<<leastSignificantBit(8)<<endl;

      
        // }      
    }
