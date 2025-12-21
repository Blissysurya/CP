
#include <bits/stdc++.h>
#include <numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back


int32_t main(){
    int t;
    cin>>t;
    while(t--){

        int n,m;
        cin>>n>>m;

        cout<<"? 1 1"<<endl;

        int dist1;
        cin>>dist1;

        if(dist1==0){
            cout<<"! 1 1"<<endl;
            continue;
        }

        cout<<"? "<<1+dist1<<" "<<1<<endl;

        int dist2;
        cin>>dist2;

        if(dist2 == 0){
            cout<<"! "<<1+dist1<<" "<<1<<endl;
            continue;
        }

        int x1=1+dist1;
        int y1=1;

        int x2=1;
        int y2=1+dist1;

        cout<<"? "<<x2<<" "<<y2<<endl;

        int dist3;
        cin>>dist3;

        if(dist3==0){
            cout<<"! "<<x2<<" "<<y2<<endl;
            continue;
        }

        int x3=x2+(abs(x1-x2))/2 ; 

        int y3=y2-(abs(y1-y2))/2;

        cout<<"? "<<x3<<" "<<y3<<endl;

        int dist4;
        cin>>dist4;


        if(dist4==0){
            cout<<"! "<<x3<<" "<<y3<<endl;
            continue;
        }

        if(( (dist2>dist3 && dist4<=dist2) && (x3-dist4/2) <= n) && ((y3+dist4/2) <= m)){
            cout<<"! "<<(x3-dist4/2)<<" "<<(y3+dist4/2)<<endl;
        }else{
            cout<<"! "<<(x3+dist4/2)<<" "<<(y3-dist4/2)<<endl;
        }


        }
    }
