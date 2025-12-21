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
struct compare{
    bool operator()(const int &lhs, const int&rhs)const{
        return lhs<rhs;
    }
};
istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
}

// string xoring(string a, string b, int n){
// string ans = "";
     
  
//     for (int i = 0; i < n; i++)
//     {
      
//         if (a[i] == b[i])
//             ans += "0";
//         else
//             ans += "1";
//     }
//     return ans;
// }
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int l1,r1,l2,r2;
        bool check=false;
        int p2;
        for(int j=n;j>=0;j--){
            if(s[j]=='0'){
                check=true;
                p2=j;
            }
        }
        if(check){
        int len=n-p2;
        int maxel=INT_MIN;
        string ans;
        for(int i=0;i<n-len;i++){
            if(s[i]=='0') continue;
            string u=s.substr(i,len);
            int p=stoll(u);
            int q=stoll(s);
            int l=p^q;
            if(maxel<l){
                maxel=l;
                ans=u;
                l2=i+1;
                r2=l2+len-1;
            }
        }
        }
        // if(check){
        // for(int i=0;i<n;i++){
        //     if(s[i]=='0'){
        //         l2=i;
        //         r2=n+i-p2-1;
        //         check=true;
        //         break;
        //     }
        // }
        // }



        if(!check){
            l2=1;
            r2=1;
        }


        l1=1;
        r1=n;

        cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    }
}

