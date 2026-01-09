
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

bool pred(int k,int h, vector<int>& vec){
    vector<int> a;
    for(int i=0;i<k;i++){
        a.push_back(vec[i]);
    }

   sort(whole(a));
   reverse(whole(a));
    int rem=h;
    int i;
   for( i=0;i<k;i+=2){
        rem-=a[i];
   }

   return rem>=0;


}

int32_t main(){
    int n,h;
    cin>>n>>h;

    vi vec(n);
    cin>>vec;

    int low=0;
    int high = n;
    int ans;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(pred(mid,h,vec)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }

        
    }

    cout<<ans<<endl;
    }
