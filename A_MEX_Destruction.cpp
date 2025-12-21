#include <bits/stdc++.h>
#include <numeric>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
// using namespace __gnu_pbds;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
// typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
//              rb_tree_tag, tree_order_statistics_node_update>
//     ordered_map;
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


int32_t main(){
    int t;
    cin>>t;
    while(t--){
            int n;
            cin>>n;
            vi vec(n);

            for(int i=0;i<n;i++){
                cin>>vec[i];
            }

            bool middle=false;

            for(int i=1;i<n-1;i++){
                if(vec[i]==0){
                    middle=true;
                    break;
                }
            }


            int count=0;

            for(int i=0;i<n;i++){
                if(vec[i]==0){
                    count++;
                }
            }

            // if(count==0){
            //     cout<<1<<endl;
            // }else{

            // if(count==n){

            //     cout<<0<<endl;

            // }else{
            // if(middle){
            //     cout<<2<<endl;
            // }else{
            // if(vec[0]==0 || vec[vec.size()-1]==0){
            //     cout<<1<<endl;
            // }
            // }}

            // }

            if(count==0){
                cout<<1<<endl;
            }else if(count==n){
                cout<<0<<endl;
                }
                else{

                    int firstZero;
                    int lastZero;
                    
                    for(int i=0;i<n;i++){
                        if(vec[i]==0){
                            firstZero=i;
                            break;
                        }
                    }

                    for(int i=n-1;i>=0;i--){
                        if(vec[i]==0){
                            lastZero=i;
                            break;
                        }
                    }
                    bool check=false;
                    bool flag=false;
                    for(int i=firstZero;i<=lastZero;i++){
                        if(vec[i]=!0){
                            check=true;
                            break;
                        }
                        if(vec[i]==0){
                            flag=true;
                            break;
                        }
                    }

                    if(check){
                        cout<<2<<endl;
                    }else{
                        cout<<1<<endl;
                    }
            }


        }   
    }
