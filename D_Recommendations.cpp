#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i].first;
            cin>>vec[i].second;
        }
        sort(vec.begin(),vec.end());
         
    }
}