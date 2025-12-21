#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;

        int c1,c2;
        c1=0;
        c2=0;

        for (size_t i = 0; i < s1.size(); i++)
        {
            if(s1[i]=='0'){
                c1++;
            }
        }
        
        for (size_t i = 0; i < n; i++)
        {
            if(s2[i]=='0'){
                c2++;
            }
        }
        if((c1%2==0 && c2%2!=0) || (c1%2!=0 && c2%2==0)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}