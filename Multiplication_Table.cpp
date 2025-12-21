#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    int low = 1;
    int high = n * n;
    int ans = -1;

    int median = (n * n + 1) / 2; 

    while (low <= high) {
        int mid = (low + high) / 2;

        int less = 0;

       
        for (int i = 1; i <= n; i++) {
            // int lo = 1;
            // int hi = n;
            int cnt = 0;

            // while (lo <= hi) {
            //     int m = (lo + hi) / 2;
            //     if (i * m <= mid) {
            //         cnt = m;      
            //         lo = m + 1;
            //     } else {
            //         hi = m - 1;
            //     }
            // }

            cnt=min(mid/i,n);
            
            less += cnt;
        }

        if (less < median) {
            low = mid + 1;
        } else {
            ans = mid;  
            high = mid - 1;
        }
    }

    cout << ans << endl;
}
