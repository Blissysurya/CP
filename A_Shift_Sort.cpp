#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;

        string t = s;
        sort(t.begin(),t.end());
        int ans = 0;

        for(int i=0; i<n ; i++)
        {
            if(t[i] =='1') break;
            if(s[i]=='1') ans++;
        }

        cout<<ans<<endl;
    }
}