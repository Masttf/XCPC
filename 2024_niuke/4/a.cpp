#include<bits/stdc++.h>
//#define int long long
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
void solve(){
	int n; cin >> n;
	vector<int> f(n + 1);
	vector<int> res(n + 1);
	vector<int> len(n + 1);
	for(int i = 1; i <= n; i++)f[i] = i;
	auto find = [&](auto self, int x) -> int{
		if(f[x] == x)return x;
		int fa = self(self, f[x]);
		len[x] += len[f[x]];
		return f[x] = fa;
	};
	auto merge = [&](int a, int b) -> void{
		f[b] = a;
		len[b] = 1;
		int fa = find(find, b);
		res[fa] = max(res[fa], res[b] + len[b]);
	};
	for(int i = 1; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		merge(a, b);
		cout << res[c] << ' ';
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}