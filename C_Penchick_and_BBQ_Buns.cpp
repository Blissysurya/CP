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

        if(n<=26){
            if(n%2!=0){
                    cout<<-1<<endl;
            }
            else{
                int i=1;
                vi out;
                while(n>0){
                    out.push_back(i);
                    out.push_back(i);
                    i++;
                    n-=2;
                }
                for (size_t i = 0; i < out.size(); i++)
                {
                    cout<<out[i]<<" ";
                }
                cout<<endl;
            }
        }
        else{
            if(n%2!=0){
                vi out(n,0);
                out[0]=1;
                out[9]=1;
                out[25]=1;

                out[26]=2;
                out[22]=2;
                out[23]=3;
                out[24]=3;
                int k=4;
                for(int i=1;i<=8;i+=2){
                    out[i]=k;
                    out[i+1]=k;
                    k++;
                }

                int z=8;
                for(int i=10;i<=21;i+=2){
                    out[i]=z;
                    out[i+1]=z;
                    z++;
                }
                int p=14;
                for(int i=27;i<n;i+=2){
                    out[i]=p;
                    out[i+1]=p;
                    p++;
                }

                for(int x=0;x<out.size();x++){
                    cout<<out[x]<<" ";

                }
                cout<<endl;
            } 
            else{
                int p=1;
                vi out(n,0);
                for(int i=0;i<n;i+=2){
                    out[i]=p;
                    out[i+1]=p;
                    p++;
                }

                for(int i=0;i<n;i++){
                    cout<<out[i]<<" ";
                }
                cout<<endl;
            }
        }
    
    }
}