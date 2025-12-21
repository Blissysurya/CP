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


int32_t main(){
        int n;
        cin>>n;
        vi vec(n);
        cin>>vec;

        // vvi dp(n+1,vector<int>(2,0));
        vi dp(n+1,0);

        dp[2]=abs(vec[1]-vec[0]);
        if(n>2){
            dp[3]=min(dp[2]+abs(vec[2]-vec[1]),abs(vec[2]-vec[0]));
        }


        for(int i=4;i<=n;i++){
            dp[i]=min(dp[i-1]+abs(vec[i-1]-vec[i-2]),dp[i-2]+abs(vec[i-1]-vec[i-3]));
        }
    //    for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    //    }
       cout<<dp[n]<<endl;
    
   
    }
