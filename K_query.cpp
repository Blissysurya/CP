
    #include <bits/stdc++.h>
    
    using namespace std;
  
    #define int long long 
    const int MAXV = 1e6;
    #define whole(x) x.begin(), x.end()
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    #define pb push_back

  
    istream& operator>>(istream& in, vi& vec) {
        for (auto& element : vec) {
            in >> element;
        }
        return in;
    }

    vector<int> a;
    vector<vector<int>> seg;
    int n, m;
    // Root node covers the range [0,n-1] or [0,n)

    vector<int> create(int num) {
    vector<int> temp;
    temp.push_back(num);
    return temp;
    }

    vector<int> combine(const vector<int>& a, const vector<int>& b) {
    int m = a.size(), n = b.size();
    int i = 0, j = 0;
    vector<int> c;

    while (i < m && j < n) {
    if (a[i] <= b[j]) {
        c.push_back(a[i]);
        i++;
    } else {
        c.push_back(b[j]);
        j++;
    }
    }

    while (i < m) {
    c.push_back(a[i]);
    i++;
    }

    while (j < n) {
    c.push_back(b[j]);
    j++;
    }
    return c;
    }

    // Range is [l,r-1] or [l,r)
    void build(int id = 1, int l = 0, int r = n) {
    if (r - l == 1) {
    seg[id] = create(a[l]);
    return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid, r);
    seg[id] = combine(seg[id * 2], seg[id * 2 + 1]);
    }
    // Time complexity: O(n*log(n))

    // x : no. of rooms
    int query(int x, int y, int k, int id = 1, int l = 0, int r = n) {
    if (r <= x || l >= y) return 0;
    if (l >= x && r <= y) {
    int ans =
        (int)seg[id].size() -
        (upper_bound(seg[id].begin(), seg[id].end(), k) - seg[id].begin());
    return ans;
    }
    int mid = (l + r) / 2;
    int l_ans = query(x, y, k, id * 2, l, mid);
    int r_ans = query(x, y, k, id * 2 + 1, mid, r);
    return l_ans + r_ans;
    }
    // Time complexity: O( log^2(N) )

    int32_t main() {
    cin >> n;

    a.resize(n);
    seg.resize(4 * n + 1);

    for (int i = 0; i < n; i++) {
    cin >> a[i];
    }

    build();
    cin >> m;

    while (m--) {
    int i, j, k;
    cin >> i >> j >> k;
    i--;
    int ans = query(i, j, k);
    cout << ans << '\n';
    }

    return 0;
    }