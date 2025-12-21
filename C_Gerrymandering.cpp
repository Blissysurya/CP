#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;

        int ans=0;
        for(int i=0,j=0;i<n && j<n;){
            if(s1[i]=='A'){
                if(s2[j]=='A'){
                    ans++;
                   if(s1[i+1]=='A'){
                    j+=2;
                    i++;
                   }else{
                    i+=2;
                    j++;
                   }
                }
                else if(s1[i+1]=='A'){
                    ans++;
                    i+=2;
                    j++;
                }
                else if(s2[j+1]=='A'){
                    ans++;
                    i++;
                    j+=2;
                }
                else if(s1[i+2]=='A'){
                    ans++;
                    i+=3;
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }

        }
    }

}