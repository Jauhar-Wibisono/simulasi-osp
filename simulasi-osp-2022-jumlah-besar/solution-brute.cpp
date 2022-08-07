#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; long long x;
	cin >> n >> x;
	vector<long long> a(n);
	for (int i=0; i<n; i++) cin >> a[i];

	long long ans = 0;
	for (int i=0; i<n; i++) {
		long long sum = 0;
		for (int j=i; j<n; j++) {
			sum += a[j];
			if (sum >= x) ans++;
		}
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