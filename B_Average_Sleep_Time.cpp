
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


int32_t main(){
    int n,k;
    cin>>n>>k;

    vi vec(n);
    cin>>vec;

    vector<int> sum;

    int i_sum = 0;

    for(int i=0;i<k;i++){
        i_sum += vec[i];
    }

    sum.push_back(i_sum);

    for(int i=k; i<n ;i++){
        i_sum = i_sum - vec[i-k]+vec[i];
        sum.push_back(i_sum);
    }

    long double ans = 0;

    int weeks = n-k+1;

    for(int i = 0 ;i < (n-k+1) ; i++){
        ans+= sum[i];
    }

    ans = ans/weeks;

    cout<<fixed<<setprecision(7)<<ans<<endl;

    }
