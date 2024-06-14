#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define scd second
#define mems(a, x) memset((a), (x), sizeof(a))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;
 
const int maxn = 1010;
const ll mod = 1000000007;
 
ll n, m, f[maxn][maxn];
 
ll dfs(ll i, ll j) {
	if (f[i][j] != -1) {
		return f[i][j];
	}
	if (!i || j == 1) {
		return 1;
	}
	return f[i][j] = (dfs(i - 1, j) + dfs(n - i, j - 1)) % mod;
}
 
void solve() {
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[i][j] = -1;
		}
	}
	printf("%lld\n", dfs(n, m));
}
 
int main() {
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}