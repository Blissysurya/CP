#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;

        vi vec(n,0);

        for(int i=y-2;i>=0;i-=2){
            if(i>=0){
            vec[i]=-1;
            }
            if(i-1>=0){
                vec[i-1]=1;
            }
        }

        for(int i=y-1;i<x;i++){
            vec[i]=1;
        }

        for(int i=x;i<n;i+=2){
            if(i<n){
                vec[i]=-1;
            }
            if(i+1 < n){
                vec[i+1]=1;
            }
        }

        for(auto it: vec){
            cout<<it<<" ";
        }

        cout<<endl;

    }
}