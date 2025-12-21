#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,v;
        cin>>n>>m>>v;
        vector<int> vec(n,0);
        vector<int> pos(m+1,0);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        bool possible=true;
        int sum=0;
        int p=0;
        for(int i=0;i<n;i++){
            sum+=vec[i];
            if(sum>=v){
                p++;
                pos[p]=i+1;
                if(p==m){
                    break;
                }
                sum=0;
            }
        }
        if(p<m){
            possible=false;
            cout<<-1<<endl;
            continue;
        }

        vector<int> x(n+1,0);
        x[0]=0;     
        
        for(int i=1;i<=n;i++){
            x[i]=x[i-1]+vec[i-1];
        }
        // int max=0;


        // for(int k=0;k<=m;k++){
         
        //     int p1=0;
        //     int p2=n-1;
            
        //         int sum1=0;
        //         int sum2=0;
        //         int c1=0;
        //         int c2=0;
        //         if(k!=0){
        //         for(int i=0;i<n;i++){
        //             sum1+=vec[i];
        //             if(sum1>=v){
        //                 c1++;
        //                 sum1=0;
        //                 if(c1==k){
        //                     p1=i+1;
        //                     break;
        //                 }
        //             }
        //         }}

        //         if(m-k != 0){
        //         for(int j=n-1;j>=0;j--){
        //             sum2+=vec[j];
        //             if(sum2>=v){
        //                 c2++;
        //                 sum2=0;
        //                 if(c2==m-k){
        //                     p2=j-1;
        //                     break;
        //                 }
        //             }
        //         }}
        //         int alice=0;
        //         for(int j=p1;j<=p2;j++){
        //             alice+=vec[j];
        //         }
        //         if(alice> max){
        //             max=alice;
        //         }
        // }
        // cout<<max<<endl;
        int ans=0;
        ans=x[n]-x[pos[m]];
        int r=n;
        for(int i=m;i>=1;i--){
            int l=pos[i-1];
            int s=0;
            while(s<v){
                s+=vec[r-1];
                // if(s>=v){
                //     break;
                // }
                r--;
            }
            ans=max(ans,x[r]-x[l]);
        }
        cout<<ans<<endl;
      
    }
}