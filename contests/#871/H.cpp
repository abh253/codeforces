#include <bits/stdc++.h>
using namespace std;
 
#define ssize(x) (int)(x).size()
 
const int MOD = 1e9 + 7;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> dp(64);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			auto new_dp = dp;
			for (int j = 0; j < 64; j++)
				new_dp[j & x] = (new_dp[j & x] + dp[j]) % MOD;
			new_dp[x] = (new_dp[x] + 1) % MOD;
			swap(dp, new_dp);
		}
		int out = 0;
		for (int i = 0; i < 64; i++)
			if (__builtin_popcount(i) == k)
				out = (out + dp[i]) % MOD;
		cout << out << '\n';
	}
	return 0;
}