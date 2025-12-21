#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[vec[i]]++;
        }
        int max=0;
        for(auto it: m){
            if(it.second > max){
                max=it.second;
            }
        }
        cout<<n-max<<endl;
    }
}