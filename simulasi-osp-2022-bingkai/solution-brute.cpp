#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<long long> a(4);
	for (int i=0; i<4; i++) cin >> a[i];

	sort(a.begin(), a.end());
	long long ans = 1e18+3;
	string comb = "0011";
	do {
		vector<int> v1, v2;
		for (int i=0; i<4; i++) {
			if (comb[i] == '0') v1.push_back(i);
			else v2.push_back(i);
		}
		for (int l1=1; l1<=1000; l1++) {
			for (int l2=1; l2<=1000; l2++) {
				ans = min(ans, abs(a[v1[0]] - l1) + abs(a[v1[1]] - l1) + abs(a[v2[0]] - l2) + abs(a[v2[1]] - l2));
			}
		}
	} while (next_permutation(comb.begin(), comb.end()));

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