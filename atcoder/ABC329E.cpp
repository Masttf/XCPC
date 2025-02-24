#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	array<bool, 5> _z;
	_z.fill(false);
	vector<array<bool, 5>> f(n, _z);
	if (s[0] == t[0]) {
		f[0][0] = true;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[i - 1][j]) {
				if (s[i] == t[0]) {
					f[i][0] = true;
				}
				if (j + 1 < m && s[i] == t[j + 1]) {
					f[i][j + 1] = true;
				}
				if (j == m - 1) {
					for (int k = 0; k < m; k++) {
						if (s[i] == t[k]) {
							f[i][k] = true;
						}
					}
				}
			}
		}
	}
	cout << (f[n - 1][m - 1] ? "Yes" : "No") << '\n';
	return 0;
}
