
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


bool vpredicate(long double time, vector<pair<long double,long double>>& vec){
    int n=vec.size();
    long double x,y;
    x= vec[0].first - time*vec[0].second;
    y= vec[0].first + time*vec[0].second;
    
    for(int i=1;i<n;i++){
        x=max(x,vec[i].first - time*vec[i].second);
        y=min(y,vec[i].first + time*vec[i].second);

        if(x > y){
            return false;
        }
    }

   return true;

}


int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<long double,long double>> vec(n);

    for(int i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }

    long double low=0;
    long double high=2e9;

    long double precision= 1e-7;
    long double ans=-1;


   for(int i=0;i<60;i++){
        long double mid= (low+high)/2;

        if(vpredicate(mid,vec)){
            high=mid;
            ans=mid;
        }else{
            low=mid;
        }
    }

    cout<<setprecision(7)<<fixed<<high<<endl;

    }
