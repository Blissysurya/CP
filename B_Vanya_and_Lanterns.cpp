#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
#define ld long double
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
   

        int n,l;
        cin>>n>>l;

        multiset<int> s;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        vi vec;
        if(s.count(0)==0){
           vec.push_back(0);
        }
        if(s.count(l)==0){
            vec.push_back(l);
        }
        

        for(auto it: s){
            vec.push_back(it);
        }
        sort(whole(vec));

        int max_dist=INT_MIN;

        for (size_t i = 0; i < vec.size(); i++)
        {
            if(vec[i]!=0){
                if((vec[i]-vec[i-1])> max_dist){
                    max_dist=vec[i]-vec[i-1];
                }
            }
        }
        
        ld p1=(ld)max_dist/(ld)2;
            int ele=0;
        for (size_t i = 0; i < vec.size(); i++)
        {
            if(vec[i]!=l){
                ele=vec[i];
            }
        }
        ld p3=l-ele;
          ld p2=(ld)*upper_bound(whole(vec),0);
        if(s.count(0)==0 && s.count(l)!=0){    
             float ans=(ld)max(p1,p2);
             
             cout<<fixed<<setprecision(10)<<ans<<endl;
             return 0;
        }
        else if(s.count(0)!=0 && s.count(l)==0){
            ld ans=(ld)max(p1,p3);
            
             cout<<fixed<<setprecision(10)<<ans<<endl;
             return 0;
        }
        else if(s.count(0)==0 && s.count(l)==0){

             ld ans=(ld)max(p1,max(p2,p3));
            
            cout<<fixed<<setprecision(10)<<ans<<endl;
            return 0; 
        }
        else{
            cout<<fixed<<setprecision(10)<<p1<<endl;
             return 0;
        }
       
}