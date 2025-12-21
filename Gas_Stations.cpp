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
    bool operator()(const pair<int,int> &lhs, const pair<int,int> &rhs)const{
        if(lhs.first!=rhs.first){
            return lhs.first < rhs.first;
        }else{
            return lhs.second > rhs.second;
        }

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


int main(){
    int l,g;
    while(cin >>l >>g){
        if(l==0 && g==0){
            break;
        }

        vector<pair<int,int>> vec;

        for(int i=0;i<g;i++){
            int x;
            int r;
            cin>>x>>r;
            int t1=x-r;
            int t2=x+r;
            if(t1<0){
                t1=0;
            }
            if(t2>l){
                t2=l;
            }
            
            vec.push_back(make_pair(t1,t2));
        }

        compare comp;
        sort(vec.begin(), vec.end(), comp);

        int cur=0;
       
        int res=0;
        
        for(int i=0;i<g && cur<l;i++){

            if(cur < vec[i].first){
                break;
            }

            int fR=vec[i].second;

            while(i+1<g && vec[i+1].first<=cur){
                fR=max(fR,vec[i+1].second);
                i++;
            }

            res++;

            cur=fR;
        }
        
        if(cur<l){
            cout<<-1<<endl;
        }else{
            cout<<g-res<<endl;
        }

    }

    }

