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

        bool check=true;

       for(int i=0;i<n;i++){
        if( i>(vec[i]) || i<(vec[i]-2)){
            check=false;
            break;
        }
       }

       if(check){
        cout<<"YES"<<endl;
       }else{
        cout<<"NO"<<endl;
       }
    }
}