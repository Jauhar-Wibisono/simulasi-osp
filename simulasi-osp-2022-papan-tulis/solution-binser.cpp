#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long x, y;
	cin >> x >> y;
	long long l = 1, r = 2e9+3, ans;
	while (l <= r) {
		long long mid = (l+r)/2;
		if (mid - mid/x >= y) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
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