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
        int n;
        cin>>n;
        vi vec(n);
        cin>>vec;


        vi b;
        b.push_back(vec[0]);
        multiset<int> s;
        s.insert(vec[0]);
        

        vi def;

        set<int> s2;

        for (size_t i = 0; i < n; i++)
        {
           s2.insert(vec[i]);
        }
        

        for(int i=1;i<=n;i++){
            if(s2.find(i)==s2.end()){
                def.push_back(i);
            }
        }

        for(int i=1;i<n-1;i++){
            if(vec[i]!=vec[i-1] && s.count(vec[i])==0){
                s.insert(vec[i]);
                b.push_back(vec[i]);
            }
            else{
                b.push_back(def.back());
                def.pop_back();
            }
        }
        b.push_back(vec[n-1]);
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}