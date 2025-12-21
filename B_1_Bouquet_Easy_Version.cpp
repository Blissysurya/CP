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
        int n,m;
        cin>>n>>m;

        vi vec(n);
        cin>>vec;
        sort(whole(vec));
        map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[vec[i]]++;
        } 

        vector<pair<int,int>> p;
        for(auto it: mp){
            p.push_back(make_pair(it.first,it.second));
        }
        int ans=0;
        for(int i=0;i<p.size()-1;i++){
            int dummy1=m;
            int dummy2=m;
            int ans1=0;
            int ans2=0;
            if(abs(p[i].first-p[i+1].first)==1){

                ans=max(ans,p[i].first*p[i].second+p[i+1].first*p[i+1].second);
                int val1=m/(p[i].first) ;
                int cnt1=min(p[i].second,val1)*p[i].first;
                cout<<"cnt 1:"<<cnt1<<" "<<p[i].first <<endl;
                dummy1-=cnt1;
                cout<<"dummy "<<dummy1<<endl;
                if(dummy1!=0){
                    int val2=dummy1/(p[i+1].first);
                    int cnt2=min(p[i+1].second,val2)*p[i+1].first;
                    cout<<"cnt 2: "<<cnt2<<" "<<val2<<" "<<p[i+1].first<<endl;
                    ans1=max(ans1,cnt1+cnt2);
                    cout<<ans1<<endl;
                }else{
                    ans1=max(ans1,cnt1);
                }



                int val3=m/(p[i+1].first) ;
                int cnt3=min(p[i+1].second,val3)*p[i+1].first;
                cout<<"cnt 3:"<<cnt3<<" "<<p[i+1].first <<endl;
                dummy2-=cnt3;
                cout<<"dummy2 "<<dummy2<<endl;
                if(dummy2!=0){
                    int val4=dummy2/(p[i].first);
                    int cnt4=min(p[i].second,val4)*p[i].first;
                    cout<<"cnt 4: "<<cnt4<<" "<<val4<<" "<<p[i].first<<endl;
                    ans2=max(ans2,cnt3+cnt4);
                    cout<<ans2<<endl;
                }else{
                    ans2=max(ans2,cnt3);
                }
                
                ans=max(ans1,ans2);

            }
        }

        for(int i=0;i<p.size();i++){

            ans=max(ans,p[i].first*p[i].second);

            

        }
        ans=min(m,ans);

        // for(int i=0;i<p.size();i++){
        //     cout<<p[i].first<<" "<<p[i].second<<endl;
        // }
        
        cout<<ans<<endl;
    }
}