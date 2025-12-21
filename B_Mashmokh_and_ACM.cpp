
#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
}

int noOfFactors(int x){

    vector<int> factors;

    for(int i=1; i*i <=x ;i++){
        if( x%i == 0 ){
            factors.push_back(i);
            if(x/i != i){
                factors.push_back(x/i);
            }
        }
    }

    int y = factors.size();
    return y;

}

int32_t main(){
    int n,k;
    cin>>n>>k;

    vector<int> dp(n+1);

    dp[0]=0;

    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+noOfFactors(i);
    }

    cout<<dp[n]<<endl;
    }
