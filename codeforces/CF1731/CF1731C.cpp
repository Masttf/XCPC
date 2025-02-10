#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 3000005;

int a[N], cnt[N];
int main() {
	int _;
	cin >> _;
	while (_--) {
		int n;
		scanf("%d", &n);
		const int wc = n * 2;
		for (int i = 0; i <= wc; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			a[i] ^= a[i - 1];
		}
		cnt[a[0]]++;
		LL ans = (LL)n * (n + 1) / 2;//总共的
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j * j <= wc; j++) {
				int t = j * j;
				ans -= cnt[t a
			}
			cnt[a[i]]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

