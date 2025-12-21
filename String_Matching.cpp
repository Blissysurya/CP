#include <bits/stdc++.h>
#include <numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;


int MOD=1e9+7;
int hashfun(string s){
    int h=0;
    for(size_t i=0;i<s.size();i++){
        h=(31*h+(s[i]-'a'+1))%MOD;
    }
    return h;
}

int32_t main(){

        string s;
        string c;
        cin>>s>>c;

        int hash_c=hashfun(c);
        
       
        int n=s.size();
        int m=c.size();
        int start_hash=hashfun(s.substr(0,m));

        int p=1;
        for(int i=0;i<m-1;i++) p=(p*31)%MOD;
        
        int count=0;
        if(hash_c==start_hash){
            count++;
        }

        for(int i=1,j=m; j<n;i++,j++){
            int del=((s[i-1]-'a'+1)*p)% MOD;
            int add=(s[j]-'a'+1)%MOD;

            start_hash= ((start_hash-del +MOD)*31+add)%MOD;
            if(hash_c==start_hash){
                count++;
            }
        }
        cout<<count<<endl;
        // cout<<hash_c<<endl;
        // cout<<start_hash<<endl;

        
    }
