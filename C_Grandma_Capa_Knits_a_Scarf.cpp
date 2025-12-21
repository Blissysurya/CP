
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

// bool isPalindrome(string s){
//     int n=s.size();
//     int i=0;
//     int j=n-1;

//     while(i<j){
//         if(s[i]!=s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }

//     return true;
// }

bool isPalindrome(string str, int start, int last) {
    while (start<last){
        if (str[start]!=str[last]) return false;
        start++;
        last--;
    }
    return true;
}

int func(string s, int start, int last, char c, int cnt){
    if (isPalindrome(s,start,last)){
        return cnt;
    }

    // if(s.size()==1 || s.size()==0){
    //     return -1;
    // }

    // int n=s.size();
    // if(s[0]!=s[s.size()-1]){
     
    //     return min(rec_func(s.substr(0,n-1),s[s.size()-1],cnt+1),rec_func(s.substr(1,n-1),s[0],cnt+1));
    // }else{
    //     return rec_func(s.substr(1,n-2),c,cnt);
    // }

    // return -1;


    // bool check=false;


    while (start<last){
        if (s[start]!=s[last]) {
            if (s[start]==c) {return func(s,start+1,last,c,++cnt);}
            else if (s[last]==c){ return func(s,start,last-1,c,++cnt);}
           
        }
        start++;
        last--;
    }
    return -1;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int start=0;
        int last=n-1;
        int ans=INT_MAX;
        
        // while(i<j){
        //     if(s[i]==s[j]){
        //         i++;
        //         j--;
        //     }else{
        //         ans=min(rec_func(s.substr(i,j-i+1),s[i],0),rec_func(s.substr(i,j-i+1),s[j],0));
        //     }
        // }
        while (start<last){
            if (s[start]!=s[last]) {
                int ans1=func(s,start+1,last,s[start],1);
                int ans2=func(s,start,last-1,s[last],1);
                if(ans1==-1 && ans2==-1){
                    ans=-1;
                }else{
                ans=min(ans1,ans2);
                }
            }
            start++;
            last--;
        }
        cout<<ans<<endl;
        }
        return 0;
    }
