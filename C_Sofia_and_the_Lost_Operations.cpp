#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// #define int long long 
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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi vec1(n);
        vi vec2(n);

        cin>>vec1;
        cin>>vec2;

        int k;
        cin>>k;

        vi vec3(k);
        cin>>vec3;
        multiset<int> s1;
        multiset<int> s2;
        map<int,int> m;

        for(int i=0;i<k;i++){
            s1.insert(vec3[i]);
        }


        for (size_t i = 0; i < n; i++)
        {
            if(vec1[i]!=vec2[i]){
                    m[vec2[i]]++;
                    s2.insert(vec2[i]);
            }
        }

        bool check=true;

        for(int i=0;i<n;i++){
            if(s1.count(vec2[i])!=s2.count(vec2[i])){
                check=false;
                break;
            }
        }

        if(check){

            int valid=0;
            bool pick=true;
            for(int j=n-1;j>=0;j--){
                if(s2.count(vec3[j])>=1){
                    valid++;
                }else{
                    if(valid==0){
                        pick=false;
                    }
                }
            }
            if(pick){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            
        }else{

            cout<<"NO"<<endl;
        }






        // bool lag=false;
        // bool extra=false;
        // for(int i=0;i<k;i++){
        //     if(m[vec3[i]]==0){
        //         extra=true;
        //     }
        // }
        // for(auto it: m){
        //     if(s.find(it.first)==s.end()){
        //         lag=true;
        //     }
        // }
        // if(lag){
        //     cout<<"NO"<<endl;
        // }
        // else{
        //     bool freq=false;
        //     for(auto it: m){
        //         if(it.second > s.count(it.first)){
        //             freq=true;
        //         }
        //     }
        //     if(freq){
        //         cout<<"NO"<<endl;
        //     }else{  
        //     bool un=false;
        //     for(auto it: s){
        //         if(m[it]==0){
        //             un=true;
        //         }
        //     }
        //     if(un){
        //     bool dextra=false;
        //     for(auto it: m){
        //         if(s.count(it.first)>m[it.first]){
                  
        //             dextra=true;
        //         }
        //     }
        //         if(dextra){
        //             cout<<"YES"<<endl;
        //         }else{
        //             cout<<"NO"<<endl;
        //         }

        //     }else{
        //         cout<<"YES"<<endl;
        //     }
        //     }
        // }

        }      
    }
