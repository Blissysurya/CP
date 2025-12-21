#include <bits/stdc++.h>
using namespace std;
#define int long long

struct compare{
    bool operator()(const int& lhs, const int& rhs ) const{
        return lhs > rhs;
    }
};


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        // int cnt=0;
        // priority_queue <int> pq (vec.begin(),vec.end());
        
        // while(pq.top()>0){
           
        //     vector<int> vec;
        //     cnt++;
        //     for(int i=0;i<x;i++){
        //         int ele=pq.top();
        //         pq.pop();
        //         ele-=1;
        //         vec.push_back(ele);
        //     }
            // for(int i=0;i<vec.size();i++){
            //     pq.push(vec[i]);
            // }
            

        // }
        // cout<<cnt<<endl;

       

        // multiset<int,compare> m;

        // for(int i=0;i<n;i++){
        //    m.insert(vec[i]);
        // }
        
        // while(!m.empty() && *m.begin()>0){
        //     cnt++;
        //     int p=0;
        //     vector<int> temp;
            
        //     for(auto it=m.begin();it != m.end()&& p<x;p++){
        //         temp.push_back(*it -1);
        //         it=m.erase(it);
        //     }
        //     for(int i=0;i<temp.size();i++){
        //         if(temp[i]>0){
        //             m.insert(temp[i]);
        //         }
        //     }
        // }
        // cout<<cnt<<endl;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=vec[i];
        }
        sort(vec.begin(),vec.end());
        int maxel=vec[vec.size()-1];
       int val=ceil((float)sum/(float)x);
       cout<<max(maxel,val)<<endl;
    }
}