#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;

	int ans = 1e9;
	for (int mask=0; mask<(1<<n); mask++) {
		bool ok = true;
		for (int i=0; i<n; i++) {
			if ((mask >> i) & 1) continue;
			for (int j=i+1; j<n; j++) {
				if (!((mask >> j) & 1)) {
					if ((a[i].first >= a[j].first && a[i].first <= a[j].second) || 
						(a[i].second >= a[j].first && a[i].second <= a[j].second) || 
						(a[j].first >= a[i].first && a[j].first <= a[i].second) || 
						(a[j].second >= a[i].first && a[j].second <= a[i].second)) {
						ok = false;
					}
				}
			}
		}
		if (ok) ans = min(ans, __builtin_popcount(mask));
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