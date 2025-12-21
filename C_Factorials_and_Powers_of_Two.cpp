#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<long long> result;
        long long prod = 6;
        for (int i = 4; prod <= n && prod > 0; i++) { // Avoid overflow
            result.push_back(prod);
            if ( prod > LLONG_MAX / i ) break; // Prevent overflow in multiplication
            prod *= i;
        }

        long long ans = LLONG_MAX;
        int m = result.size();

        for (int mask = 0; mask < (1 << m); mask++) {
            long long sum = n;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    sum -= result[i];
                }
            }

            if (sum < 0) continue; // Invalid subset
            ans = min((long long)(__builtin_popcountll(mask) + __builtin_popcountll(sum)), ans);
        }

        cout << ans << endl;
    }
}
