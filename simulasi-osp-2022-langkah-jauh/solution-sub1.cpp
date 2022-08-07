#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void solve() {
	int n;
	cin >> n;
	vector<string> g(n);
	for (int i=0; i<n; i++) cin >> g[i];

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i+1 < n) {
				dp[i+1][j] += dp[i][j]; 
				dp[i+1][j] %= mod;
			}
			if (j+1 < n) {
				dp[i][j+1] += dp[i][j];
				dp[i][j+1] %= mod;
			}
		}
	}

	cout << dp[n-1][n-1] << '\n';
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