#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;

struct compare1{
    bool operator()(const int& lhs,const int& rhs) const {
        return lhs >rhs;
    }
};

struct compare2{
    bool operator()(const int& lhs,const int& rhs) const {
        return lhs < rhs;
    }
};

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi vec(n);
         set<int,compare1> s1;
         set<int,compare2> s2;
        for (size_t i = 0; i < n; i++)
        {
            cin>>vec[i];
            s1.insert(vec[i]);
            s2.insert(vec[i]);
        }
        int ptr1=0;
        int ptr2=n-1;
    int l=0;
    int r=0;
        while(ptr1 < ptr2){
            if(vec[ptr1]==*s2.begin()  ){
                    ptr1++;
                    s2.erase(*s2.begin());
                    s1.erase(*s2.begin());
                   
            }
            else if( vec[ptr2]==*s1.begin()  ){
                ptr2--;
                s1.erase(*s1.begin());
                s2.erase(*s1.begin());
            }
            else if(vec[ptr1]==*s1.begin()){
                ptr1++;
                s1.erase(*s1.begin());
                s2.erase(*s1.begin());
            }
            else if(vec[ptr2]==*s2.begin()){
                ptr2--;
                s2.erase(*s2.begin());
                s1.erase(*s2.begin());
            }
            else{
                l=ptr1+1;
                r=ptr2+1;
                break;
            }
        }
       
        if(l!=0){
            cout<<l<<" "<<r<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }}
    