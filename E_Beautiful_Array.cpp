#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int a,b;
    cin>>a>>b;
    cout<<3<<endl;
    vector<int> vec(3,a);
    if(b>=a){
    vec[1]=b;
    vec[0]=vec[0]-b+a;
    vec[2]=b+1;
    vec[0]=vec[0]-(b+1-a);
    }
    else{
        vec[1]=b;
      
        vec[0]=b-1;
        vec[2]=vec[2]+(a-b)+(a+1-b);
    }
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;

}