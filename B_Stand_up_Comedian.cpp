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
       vi vec(4,0);
       for (size_t i = 0; i < 4; i++)
       {
        cin>>vec[i];
       }

       int a=0;
       int b=0;
       int ans=0;

        a+=vec[0];
        b+=vec[0];
        ans+=vec[0];
        int state=0;
       while(true){
        
        if((state!=1 || vec[2]==0) && vec[1]!=0){
            if(vec[1]<b ){
                ans+=vec[1];
                b=b-vec[1];
                a+=vec[1];
                vec[1]=0;
                state=1;
            }else{
                ans+=b;
                a+=b;
                b=0;
                
                vec[1]-=b;
                state=1;
            }
        }
        else if((state!=-1 || vec[1]==0) && vec[2]!=0){
                if(vec[2]<a){
                    ans+=vec[2];
                    a-=vec[2];
                    b+=vec[2];
                    vec[2]=0;
                    state=-1;
                }
                else{
                    ans+=a;
                    b+=a;
                    vec[2]-=a;
                    a=0;
                    state=-1;
                }
        }

 if (a == 0 && vec[1] == 0) {
    if (vec[2] != 0 || vec[3] != 0) {
        ans += 1;
    }
    break;
} else if (b == 0 && vec[2] == 0) {
    if (vec[1] != 0 || vec[3] != 0) {
        ans += 1;
    }
    break;
} else if (a != 0 && b != 0 && vec[1] == 0 && vec[2] == 0) {
    if (vec[3] != 0) {
        ans += 1;
    }
    break;
}

       }

       cout<<ans<<endl;
 
       
    }
}