#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << abs(d - c) << '\n';
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