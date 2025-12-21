#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;

        int delx=0;
        int dely=0;
    int count=0;
    bool check=false;
    while(count<1000){
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                dely++;
                if(delx==a && dely==b){
                    check=true;
                    break;
                        }
            }else if(s[i]=='S'){
                dely--;
                 if(delx==a && dely==b){
                    check=true;
                    break;
                        }
            }
            else if(s[i]=='E'){
                delx++;
                 if(delx==a && dely==b){
                    check=true;
                    break;
                        }
            }else{
                delx--;
                 if(delx==a && dely==b){
                    check=true;
                    break;
                        }
            }
        }
        if(check){
            break;
        }
        
        count++;
    }


    if(check){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
  
    }
}