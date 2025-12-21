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


int32_t main(){
    int t;
    cin>>t;
    // leastPrimeFactor(MAXV);
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        vi a(m);
        vi b(k);
        cin>>a;
        cin>>b;

        set<int> s;

        for(int i=0;i<k;i++){
            s.insert(b[i]);
        }

        string ans(m,'0');
        
        if(n-k>=2){
            
        }
        else if(n==k){
            for(int i=0;i<m;i++){
                ans[i]='1';
            }
        }
        else{
            int num=0;
            for(int i=0;i<n;i++){
                if(s.find(a[i])==s.end()){
                   num=a[i];
                }
            }

            num--;
            ans[num]='1';
            
            
        }

        cout<<ans<<endl;
      
        }      
    }
