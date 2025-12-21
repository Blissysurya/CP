#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        int v=k+k/(n-1);
        if(v%n==0){
            cout<<v-1<<endl;
        }
        else{
            cout<<v<<endl;
        }

    }
}