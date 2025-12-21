#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
    int n, w;
    cin >> n >> w;

    vector<multiset<int>> vec(w + 1);
    vector<pair<int, int>> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].insert(y);
        pos[i] = {x, y};
    }

    int q;
    cin >> q;

    int maxi = INT_MIN;

    // Fixing the loop range for correct max calculation
    for (int i = 1; i <= w; i++) {
        if (!vec[i].empty()) {
            maxi = max(maxi, *(vec[i].rbegin()));
        }
    }

    while (q--) {
        int t, x;
        cin >> t >> x;

        int val = pos[x].second;  // Extract stored y value

        if (val < t ) {
            cout << "No" << endl;
        } else {
            if(val >= maxi){
            cout << "Yes" << endl;
            }else{
                if(vec[i])
                cout<<"No"<<endl;
            }
        }
    }

    return 0;
}
