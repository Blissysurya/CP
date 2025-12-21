
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

bool check(int x, vector<int> vec){
    vector<int> temp=vec;
    int n= vec.size();
    for(int i=n-1;i>=2;i--){
        if(vec[i]<x){continue;}
        int d1= min(temp[i]/3,(vec[i]-x)/3);
        vec[i]-=3*d1;
        vec[i-1]+=d1;
        vec[i-2]+=2*d1;
    }

    bool poss=true;

    for(int i=0;i<n;i++){
        if(vec[i] < x){
            poss=false;
            break;
        }
    }

    return poss;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vi vec(n);
        cin>>vec;

        int low=1;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            
            int mid=(low+high)/2;

            if(check(mid,vec)){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }

        }

        cout<<ans<<endl;

        }
    }
