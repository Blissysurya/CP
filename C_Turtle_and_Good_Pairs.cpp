#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
    vi vec(26);
    for(int i=0;i<n;i++){
        ++vec[s[i]-'a'];
    }

    int mc=max_element(whole(vec))-vec.begin();
    string t(vec[mc],'a'+mc);

    for(int i=0;i<26;i++){
        if(i!=mc){
            t+=string(vec[i],'a'+i);
        }
    }

    vi indices;
    for(int i=0;i<n;i+=2){
        indices.push_back(i);
    }
    for(int i=1;i<n;i+=2){
        indices.push_back(i);
    }

    string ans(n, ' ');

    for (int i = 0; i < n; i++)
    {
        ans[indices[i]]=t[i];
    }
    cout<<ans<<endl;

    }
}