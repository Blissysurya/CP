
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




int32_t main(){
    
    string s1;
    string s2;

    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    vvi dp(n+1,vi(m+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
            dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    cout<<dp[n][m]<<endl;

    }
