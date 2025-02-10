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
struct node{
	int val, r_val, tag;
};
void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s = ' ' + s;
	vector<int>p(n + 1);
	vector<int>f(n + 1);
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] * 131;
		f[i] = f[i - 1] * 131 + s[i] - 'a' + 1;
	}
	auto get_hash = [&](int l, int r) -> int{
		return f[r] - f[l - 1] * p[r - l + 1];
	};
	vector<vector<int>>div(n + 1);
	vector<bool>vis(n + 1);
	for(int i = 2; i <= n; i++){
		if(!vis[i]){
			for(int j = i; j <= n; j += i){
				vis[j] = 1;
				int t = j;
				while(t % i == 0){
					t /= i;
					div[j].push_back(i);
				}
				
			}
		}
	}
	auto get = [&](int l, int r) -> int{
		auto check = [&](int len) -> bool{
			if(len == r - l + 1)return true;
			int l1 = l, r1 = r - len;
			int l2 = l + len, r2 = r;
			if(get_hash(l1, r1) == get_hash(l2, r2))return true;
			else return false;
		};

		int ans = r - l + 1;
		int len = r - l + 1;
		for(auto x : div[len]){
			int v = ans / x;
			if(check(v))ans = v;
		}
		return ans;
	};
	int m; cin >> m;
	for(int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		cout << get(l, r) << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}