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
     vi vec(1e6+1,1);
        vec[0]=0;
        vec[1]=0;
        for(int i=2;i*i<=1e6;i++){
            if(vec[i]==1){
            for(int j=i*i;j<=1e6;j+=i){
                vec[j]=0;
            }
            }
        }

        vi tuples(1e6+1,0);
        for(int i=5;i<=1e6;i++){
            if(vec[i]==1 && vec[i-2]==1){
                tuples[i]=tuples[i-1]+1;
            }else{
                tuples[i]=tuples[i-1];
            }
        }
    while(t--){
        int n;
        cin>>n;
       
        cout<<tuples[n]<<endl;
    }
}