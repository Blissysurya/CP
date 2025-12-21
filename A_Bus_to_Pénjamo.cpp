#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;

        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }

        int full_occ_rows=0;
        for(int i=0;i<n;i++){
            full_occ_rows+=vec[i]/2;
            vec[i]=vec[i]%2;
        }
        r=r-full_occ_rows;
        int people_rem=0;
        for(int i=0;i<n;i++){
            people_rem+=vec[i];
        }
        int half_occ_rows=0;
        if(r==people_rem){
            half_occ_rows=people_rem;
        }
        else if(r>people_rem){
             half_occ_rows=people_rem;
        }
        else{
            half_occ_rows=2*r-people_rem;
        }
        cout<<2*full_occ_rows+half_occ_rows<<endl;
    }
}