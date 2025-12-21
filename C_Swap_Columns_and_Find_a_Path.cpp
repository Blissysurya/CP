#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> row1(n,0);
        vector<int> row2(n,0);

        for(int i=0;i<n;i++){
            cin>>row1[i];
        }

        for(int i=0;i<n;i++){
            cin>>row2[i];
        }
        int maxel=INT_MIN;
        
        for(int i=0;i<n;i++){
            int sum=0;
            sum+=row1[i]+row2[i];
            for(int j=0;j<i;j++){
                sum += max(row1[j],row2[j]);
            }
            for(int j=i+1;j<n;j++){
                sum+= max(row1[j],row2[j]);
            }

            if(sum>maxel){
                maxel=sum;
            }
        }

        cout<<maxel<<endl;
    }
}