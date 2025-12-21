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
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        reverse(whole(s));
        for(int i=0;i<s.size();i++){
            if(s[i]=='p'){
                s[i]='q';
            }
            else if(s[i]=='q'){
                s[i]='p';
            }
        }
        cout<<s<<endl;
    }
}