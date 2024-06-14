#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> pos(2);
    std::vector<std::vector<i64>> pref(2);
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') {
            pos[0].emplace_back(i);
            pref[0].emplace_back(i);
            int sz = pref[0].size();
            if (sz > 1) {
                pref[0][sz - 1] += pref[0][sz - 2];
            }
        } else {
            pos[1].emplace_back(i);
            pref[1].emplace_back(i);
            int sz = pref[1].size();
            if (sz > 1) {
                pref[1][sz - 1] += pref[1][sz - 2];
            }
        }
    }
    auto sum = [&](int x, int l, int r) {
        if (l > r) {
            return 0LL;
        }
        return pref[x][r] - (l > 0 ? pref[x][l - 1] : 0);
    };
    for (int i = 0; i < n; i++) {
        int il = std::lower_bound(pos[0].begin(), pos[0].end(), i) - pos[0].begin() - 1;
        int ir = std::upper_bound(pos[1].begin(), pos[1].end(), i) - pos[1].begin();
        int cntl = il + 1;
        int cntr = (int) pos[1].size() - ir;
        
        if (s[i] == '>') {
            if (cntl < cntr) {
                i64 res = 2LL * cntl * i - 2 * sum(0, 0, il) + 2 * sum(1, ir, ir + cntl) - 2LL * (cntl + 1) * i + (i + 1);
                std::cout << res << " ";
            } else {
                i64 res = 2LL * cntr * i - 2 * sum(0, il - cntr + 1, il) + 2 * sum(1, ir, (int) pos[1].size() - 1) - 2LL * cntr * i + (n - i);
                std::cout << res << " ";
            }
        } else {
            if (cntr < cntl) {
                i64 res = 2LL * (cntr + 1) * i - 2 * sum(0, il - cntr, il) + 2 * sum(1, ir, (int) pos[1].size() - 1) - 2LL * cntr * i + (n - i);
                std::cout << res << " ";
            } else {
                i64 res = 2LL * cntl * i - 2 * sum(0, 0, il) + 2 * sum(1, ir, ir + cntl - 1) - 2LL * cntl * i + (i + 1);
                std::cout << res << " ";
            }
        }
    }
    std::cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/home/q1n/coding/input.txt", "r", stdin);
        freopen("/home/q1n/coding/output.txt", "w", stdout);
    #else
        // online submission
    #endif

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }
}