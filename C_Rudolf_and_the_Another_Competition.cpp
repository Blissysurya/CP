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

struct triplet{
    int s,i,p;

    triplet(int s,int i, int p){
        this->s=s;
        this->i=i;
        this->p=p;
    }
};

struct compare2 {
    bool operator()(const triplet& lhs, const triplet& rhs) {
        if (lhs.s != rhs.s) {
            return lhs.s > rhs.s;
        } else {
            return lhs.p < rhs.p;
        }
    }
};


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,h;
        cin>>n>>m>>h;

        vector<vector<int>> vec(n,vector<int>(m));
        vector<vector<int>> pre(n,vector<int>(m));
       for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>vec[i][j];
                  
                }
       }
       for(int i=0;i<n;i++){
            sort(whole(vec[i]));
       }

        for (int i = 0; i < n; i++) {
            pre[i][0] = vec[i][0];
            for (int j = 1; j < m; j++) {
                pre[i][j] = pre[i][j - 1] + vec[i][j];
            }
        }

        vector<triplet> a;
       for(int i=0;i<n;i++){
                int s=0;
                int p=0;
                int t=0;
                for(int j=0;j<m;j++){
                    if(t+vec[i][j] <= h){
                        t+=vec[i][j];
                        s++;    
                        p+=pre[i][j];
                    }
                }
            a.emplace_back(s,i,p);
       }
        sort(whole(a),compare2());
        int ans=0;
        int pp=0;
        int ss=0;
        // for(int j=0;j<a.size();j++){
        //     if(a[j].i==0){
              
        //         pp=a[j].p;
        //         ss=a[j].s;
        //         break;
        //     }
        // }
        
        for(int j=0;j<a.size();j++){
                if(a[j].i==0 ){
                    ans=j;
                    break;
                }
        }

        cout<<ans+1<<endl;
    }
}
