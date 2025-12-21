#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n,0);

        for(int i=0;i<n;i++){
            cin>>vec[i];
        }

        int state=0;
        int len1=0;

        vector<int> arr;
        for(int i=0;i<n-1;i++){
            if(vec[i]<vec[i+1] && state!=1){
                len1++;
                state=1;
            }
            else if(vec[i]>vec[i+1] && state!=-1){
                len1++;
                state=-1;
            }
        }
        cout<<len1+1<<endl;
    }
}