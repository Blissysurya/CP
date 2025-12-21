#include <bits/stdc++.h>
using namespace std;

long long calculateSum(vector<int>& a, int n) {
    int m = a.size(); // Size of the array
    sort(a.begin(), a.end()); // Sort the array
    
    // Precompute suffix sums
    vector<long long> suffixSum(m + 1, 0);
    for (int i = m - 1; i >= 0; --i) {
        suffixSum[i] = suffixSum[i + 1] + a[i];
    }

    long long sum = 0;

    for (int i = 0; i < m; ++i) {
        // Binary search to find first index j > i where a[i] + a[j] > n - 1
        int l = i + 1, r = m - 1, idx = m;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[i] + a[mid] > n - 1) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // All elements from idx to m-1 satisfy the condition
        int count = m - idx;
        if (count > 0) {
            // Add contributions from these pairs
            sum += (long long)a[i] * count;          // Contribution from a[i]
            sum += suffixSum[idx];                  // Contribution from all elements after idx
            sum -= (long long)(n - 1) * count;      // Subtract (n-1)*count as per formula
        }
    }

    return sum;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int m, n;
        cin >> m >> n; // Input array size and value of n

        vector<int> a(m);
        for (int &x : a)
            cin >> x;

        cout << calculateSum(a, n) << endl;
    }

    return 0;
}
