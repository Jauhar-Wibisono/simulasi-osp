#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), [](pair<int, int> aa, pair<int, int> bb){
		if (aa.second != bb.second) return aa.second < bb.second;
		return aa.first < bb.first;
	});
	int r = -1e9-3;
	int ans = 0;
	for (int i=0; i<n; i++){
		if (a[i].first > r){
			ans++;
			r = a[i].second;
		}
	}
	cout << n - ans << '\n';
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