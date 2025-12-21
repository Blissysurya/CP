#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n), c(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        for (auto &x : c) cin >> x;

        long long ans = 0;

        // permutation 1: A, B, C
        long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
        int idx1 = -1, idx2 = -1, idx3 = -1;

        for (int i = 0; i < n; i++) if (a[i] > max1) max1 = a[i], idx1 = i;
        for (int i = 0; i < n; i++) if (i != idx1 && b[i] > max2) max2 = b[i], idx2 = i;
        for (int i = 0; i < n; i++) if (i != idx1 && i != idx2 && c[i] > max3) max3 = c[i], idx3 = i;

        ans = max(ans, max1 + max2 + max3);

        // permutation 2: A, C, B
        max1 = max2 = max3 = LLONG_MIN;
        idx1 = idx2 = idx3 = -1;

        for (int i = 0; i < n; i++) if (a[i] > max1) max1 = a[i], idx1 = i;
        for (int i = 0; i < n; i++) if (i != idx1 && c[i] > max3) max3 = c[i], idx3 = i;
        for (int i = 0; i < n; i++) if (i != idx1 && i != idx3 && b[i] > max2) max2 = b[i], idx2 = i;

        ans = max(ans, max1 + max2 + max3);

        // permutation 3: B, A, C
        max1 = max2 = max3 = LLONG_MIN;
        idx1 = idx2 = idx3 = -1;

        for (int i = 0; i < n; i++) if (b[i] > max2) max2 = b[i], idx2 = i;
        for (int i = 0; i < n; i++) if (i != idx2 && a[i] > max1) max1 = a[i], idx1 = i;
        for (int i = 0; i < n; i++) if (i != idx1 && i != idx2 && c[i] > max3) max3 = c[i], idx3 = i;

        ans = max(ans, max1 + max2 + max3);

        // permutation 4: B, C, A
        max1 = max2 = max3 = LLONG_MIN;
        idx1 = idx2 = idx3 = -1;

        for (int i = 0; i < n; i++) if (b[i] > max2) max2 = b[i], idx2 = i;
        for (int i = 0; i < n; i++) if (i != idx2 && c[i] > max3) max3 = c[i], idx3 = i;
        for (int i = 0; i < n; i++) if (i != idx2 && i != idx3 && a[i] > max1) max1 = a[i], idx1 = i;

        ans = max(ans, max1 + max2 + max3);

        // permutation 5: C, A, B
        max1 = max2 = max3 = LLONG_MIN;
        idx1 = idx2 = idx3 = -1;

        for (int i = 0; i < n; i++) if (c[i] > max3) max3 = c[i], idx3 = i;
        for (int i = 0; i < n; i++) if (i != idx3 && a[i] > max1) max1 = a[i], idx1 = i;
        for (int i = 0; i < n; i++) if (i != idx1 && i != idx3 && b[i] > max2) max2 = b[i], idx2 = i;

        ans = max(ans, max1 + max2 + max3);

        // permutation 6: C, B, A
        max1 = max2 = max3 = LLONG_MIN;
        idx1 = idx2 = idx3 = -1;

        for (int i = 0; i < n; i++) if (c[i] > max3) max3 = c[i], idx3 = i;
        for (int i = 0; i < n; i++) if (i != idx3 && b[i] > max2) max2 = b[i], idx2 = i;
        for (int i = 0; i < n; i++) if (i != idx2 && i != idx3 && a[i] > max1) max1 = a[i], idx1 = i;

        ans = max(ans, max1 + max2 + max3);

        cout << ans << "\n";
    }
}
