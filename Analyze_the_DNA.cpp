
    #include <bits/stdc++.h>

    using namespace std;

    #define vi vector<int>
    #define whole(x) x.begin(), x.end()

    int main(){
        int t;
        cin>>t;
        while(t--){
            string s;
            cin>>s;

            int n=s.size();
            int lim;
            int stlim;
            for(int i=n-1;i>=0;i--){
                if(s[i]=='A'){
                    lim=i;
                    break;
                }
            }

            for(int i=0;i<n;i++){
                if(s[i]=='A'){
                    stlim=i;
                    break;
                }
            }

            lim++;
            stlim;

            string p=s.substr(0,lim);
            p=p.substr(stlim);
    
            int m=p.size();

            string q=p;
            reverse(whole(q));
            int l=q.size();

            vector<vector<int>> dp(l+1,vi(m+1,0));
        

            for(int i=1;i<=l;i++){
                for(int j=1;j<=m;j++){

                    if(q[i-1]==p[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }else{  
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
        }

        cout<< dp[l][m]<<" ";

            int lim1;
            int stlim1;
            for(int i=n-1;i>=0;i--){
                if(s[i]=='G'){
                    lim1=i;
                    break;
                }
            }

            for(int i=0;i<n;i++){
                if(s[i]=='G'){
                    stlim1=i;
                    break;
                }
            }

            lim1++;
            stlim1;

            string p1=s.substr(0,lim1);
            p1=p1.substr(stlim1);
    
            int m1=p1.size();

            string q1=p1;
            reverse(whole(q1));
            int l1=q1.size();

            vector<vector<int>> dp1(l1+1,vi(m1+1,0));
        

            for(int i=1;i<=l1;i++){
                for(int j=1;j<=m1;j++){

                    if(q1[i-1]==p1[j-1]){
                        dp1[i][j]=1+dp1[i-1][j-1];
                    }else{  
                        dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
                    }
                }
        }   

            cout<<dp1[l1][m1]<<endl;

            }
        }
