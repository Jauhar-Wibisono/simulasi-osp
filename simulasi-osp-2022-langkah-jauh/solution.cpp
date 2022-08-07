#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void solve() {
	int n;
	cin >> n;
	vector<string> g(n);
	for (int i=0; i<n; i++) cin >> g[i];

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
	dp[0][0][0] = 1;
	for (int r=0; r<n; r++) {
		for (int c=0; c<n; c++) {
			for (int k=0; k<n; k++) {
				if (r+k+1 < n) {
					dp[r+k+1][c][k + (g[r+k+1][c] == '+')] += dp[r][c][k];
					dp[r+k+1][c][k + (g[r+k+1][c] == '+')] %= mod;
				}
				if (c+k+1 < n) {
					dp[r][c+k+1][k + (g[r][c+k+1] == '+')] += dp[r][c][k];
					dp[r][c+k+1][k + (g[r][c+k+1] == '+')] %= mod;	
				}
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; i++) {
		ans += dp[n-1][n-1][i];
		ans %= mod;
	}

	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	while (tcs--) {
		solve();
	}
	return 0;
}