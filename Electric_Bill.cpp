#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
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

int f1(int mid){
        int cost=0; 
        if(mid<=100){
            cost+=2*mid;
        }
        else if(mid>100 && mid<=10000){
            cost+=2*100+3*(mid-100);
        }
        else if(mid>10000 && mid<=1000000){
            cost+=2*100 + 9900*3 + 5*(mid-10000);
        }
        else if(mid>1000000){
            cost+=2*100 +9900*3+990000*5+(mid-1000000)*7;
        }

        return cost;
}

int32_t main(){

        while(true){
            int x,y;
            cin>>x>>y;

            if(x==0 && y==0){
                break;
            }

            int lo=1;
            int hi=1e9;

            while(lo<=hi){
                    int mid=lo+(hi-lo)/2;
                    if(f1(mid) < x){
                        lo=mid+1;
                    }else{
                        hi=mid-1;
                    }
            }

            //Second binary search

            int low=0;
            int high=lo>>1;
            int ans=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                int h=lo-mid;
                if(f1(h)-f1(mid) == y){
                    ans=mid;
                    break;
                }
                else if(f1(h)-f1(mid) < y){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }

            cout<<f1(ans)<<endl;
        }

    }
