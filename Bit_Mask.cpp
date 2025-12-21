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

string dec_to_bin(int x){
    string str;
    while(x>0){
        if(x&1){
            str+="1";
        }else{
            str+="0";
        }

         x>>=1;
    }
    reverse(whole(str));
    return str;
}

int bin_to_dec(string s){
    int num=0;
    for(int i=0;i<s.size();i++){
        num*=2;
        num+=(s[i]-'0');
    }
    return num;
}

int32_t main(){
    int n,l,r;

    while(cin >> n >> l >> r){
        // string str_n=dec_to_bin(n);
        // string str_l=dec_to_bin(l);
        // string str_u=dec_to_bin(u);
        // int diff=str_u.size()-str_l.size();
        // string out;
        // for(int i=0;i<diff;i++){
        //     out+="0";
        // }
        // string out2=out;
        // out+=str_l;
        // str_l=out2+str_l;
        // int d=max(str_n.size(),out.size())-min(str_n.size(),out.size());

        // bool small=false;
        // for(int i=0;i<out.size();i++,d++){
        //         if(str_n[d]=='0' && str_u[i]=='1' && out[i]=='0'){
        //                 out[i]='1';
        //         }
        //         if(str_n[d]=='1' && str_u[i]=='1' ){
        //                 small=true;
        //         }
        //         if(small){
        //                 if(str_n[d]=='0' && str_u[i]=='0'){
        //                     out[i]='1';
        //                 }
        //         }
        // }   
        // cout<<str_n<<endl;
        // cout<<str_u<<endl;
        // cout<<str_l<<endl;
        // cout<<out<<endl;
        // cout<<bin_to_dec(out)<<endl;
        int x = 0;
        int L,R;
        // cout << n << ' ' << l << ' ' << r << '\n';
        for(int i=31;i>=0;i--){ 
            // if((1LL<<i)&n) continue;
            if(n&(1LL<<i)){
            L=x+1LL<<i;
            if(x <= l){
                x=x+1LL<<i;
            }
            // x += (1LL<<i);
            // if(x>r) x -= (1LL<<i);
        }
        cout << x << ' ';
        for(int i=31; i>-1; i--) {
            // bool f = ((1LL<<i)&x);
            // if(!f) {
            //     x += (1LL<<i);
            //     if(x>r) x -= (1LL<<i);
            // }
            // if(x>=l) break;
            
        }
        cout << x << endl;
    }
    }
