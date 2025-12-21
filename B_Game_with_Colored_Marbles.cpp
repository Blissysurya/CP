#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n,0);
         vector<int> freq(1001,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<n;i++){
            freq[vec[i]]++;
        }
       int ones=0;
       int alice=0;
       for(int i=0;i<freq.size();i++){
        if(freq[i]==1){
            ones++;
            freq[i]=0;
        }
       }
       alice+=2*ceil((float)ones/(float)2);
    
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0){
                alice++;
            }
        }

        cout<<alice<<endl;
    }
}
