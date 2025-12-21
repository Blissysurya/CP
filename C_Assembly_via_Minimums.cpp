#include <bits/stdc++.h>
using namespace std;
// #define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p=(n*(n-1))/2;

        vector<int> vec(p,0);
        for (size_t i = 0; i < p; i++)
        {
            cin>>vec[i];
        }

        sort(vec.begin(),vec.end());
        vector<int> ans;
        int k=0;
        int j=0;
        int idx=0;

        if(n==2){
            cout<<vec[0]<<" "<<vec[0]<<endl;
        }else{
        ans.push_back(vec[0]);
        for(int i=1;i<n && idx<p;i++){
            j++;
            k+=j;
            idx=i*n-k;
            ans.push_back(vec[idx]);
            if(ans.size()==n-1){
                break;
            }
        }
        ans.push_back(vec[vec.size()-1]);
        
        for(auto it: ans){
            cout<<it<<" ";
        }
        
        cout<<endl;
        }
    }
}