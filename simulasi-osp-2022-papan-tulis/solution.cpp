#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	cout << y + (y-1)/(x-1) << '\n';
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