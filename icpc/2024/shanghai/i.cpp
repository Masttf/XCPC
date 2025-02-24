#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	dbg(x);\
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

constexpr int mod = 998244353;

void solve(){
	int n, k;
	cin >> n >> k;
	priority_queue<int> q;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		q.push(x);
	}
	int mx = q.top() % mod;
	if(k == 1) {
		cout << mx << '\n';
		return ;
	}
	int mul = 1;
	for(int i = 1; i <= k; ++i) {
		if(q.empty() || q.top() == 0) {
			cout << mx << '\n';
			return ;
		}
		mul = mul * q.top() % mod;
		q.pop();
	}
	int last = mul;
	while(1) {
		for(int i = 1; i < k; ++i) {
			if(q.empty() || q.top() == 0) {
				cout << last << '\n';
				return ;
			}
			mul = mul * q.top() % mod;
			q.pop();
		}
		last = mul;
	}
	cout << last << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}