#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
using Pii = std::pair<int, int>;
int qpow(int a, int b) {
	int sum = 1;
	while(b) {
		if(b & 1) sum = sum * a;
		a *= a;
		b >>= 1;
	}
	return sum;
}
void solve(){
	int c, a, b;
	std::cin >> c >> a >> b;
	int l = 0, r = 10, ans = 0;
	auto check = [&](int x)->Pii {
		int up = qpow(a, x) * c - qpow(b, x) * x;
		int down = qpow(b, x);
		int k = std::gcd(up,down);
		return {up / k, down / k};
	};
	bool cmp(Pii a, Pii b) {
		return a.first * b.second > a.second * b.first;
	}
	while(l < r) {
		int lmid = l + (r - l) / 3;
		int rmid = r - (r - l) / 3;
		Pii lans = check(lmid), rans = check(rmid);
		if(cmp(lans, rans)) r = rmid - 1;
		else l = lmid + 1;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}