#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }

        int maxf=0;
        int minf=INT_MAX;
        char minch;
        char maxch;

        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0 &&  maxf < freq[i]){
                maxf=freq[i];
                maxch='a'+i;
            }
            if(freq[i]!=0 && freq[i] < minf){
                minf=freq[i];
                minch='a'+i;
            }
        }
        if(maxch!=minch){
            for(int i=0;i<n;i++){
                if(s[i]==minch){
                    s[i]=maxch;
                    break;
                }
            }
        }else{
            for(int i=0;i<n;i++){
                if(s[i]!=maxch){
                    s[i]=maxch;
                    break;
                }
            }
        }
        cout<<s<<endl;

    }
}