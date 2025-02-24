#include<bits/stdc++.h>
using namespace std;

#define N 1000007
#define mod 998244353

int f[N] = {0, 1}, ans[N];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; i * j <= n; j++) (f[j * i + 1] += f[i]) %= mod;
	for (int i = 1; i <= n; ++i) 
		for (int j = i; j <= n; j += i) (ans[j] += f[i]) %= mod;
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}