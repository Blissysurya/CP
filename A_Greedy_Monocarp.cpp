#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        int lump=0;
        for(int i=0;i<n;i++){
           if(lump +vec[i] <= k){
            lump=lump+vec[i];
           }else{
            break;
           }
        }   
        
        cout<<k-lump<<endl;
    }
}