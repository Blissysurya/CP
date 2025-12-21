#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// #define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
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

string dec_to_bin(int dec){
        string bin;
        while(dec>0){
            if(dec & 1){
                bin+="1";
            }else{
                bin+="0";
            }
            dec >>= 1;
        }
        reverse(whole(bin));
        return bin;
}   

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;

        int a=l;
        int b=r;
       
       string max=dec_to_bin(b);
       string min=dec_to_bin(a);

       int m=max.size();
       int mi=min.size();
       int diff=m-mi;

       string real;
       for(int i=0;i<diff;i++)
      {
        real+="0";
      }

        real+=min;

        string out;
        bool f=false;
        for(int i=0;i<real.size();i++){
            if(!f && max[i]=='1' && min[i]=='1'){
                out+="1";
                
            }
            else if(f && max[i]=='1' && min[i]=='1' ){
                out+="0";
            }
            else{
                out+="1";
                f=true;
            }
        }

        

        int i=stoi(out,0,2);

        if()
        
        cout<<a<<" "<<b<<" "<<i<<endl;

       
        }

    }
