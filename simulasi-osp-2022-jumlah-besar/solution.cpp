#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; long long x;
	cin >> n >> x;
	vector<long long> a(n+1);
	for (int i=1; i<=n; i++) cin >> a[i];

	vector<long long> p(n+1, 0);
	for (int i=1; i<=n; i++) p[i] = p[i-1] + a[i];

	long long ans = 0;
	for (int i=1; i<=n; i++) {
		int l = i, r = n, rb = n+1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (p[mid] - p[i-1] >= x) {
				rb = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans += n - rb + 1;
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