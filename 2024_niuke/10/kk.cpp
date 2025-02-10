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
constexpr int Max = 1e18;
void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>>a(m + 1);
	int N = 1;
	for(int i = 1; i <= n; i++)N = N * 10; 
	for(int i = 1; i <= m; i++){
		int t, cnt; cin >> t >> cnt;
		a[i] = {t, cnt};
	}
	auto get_num = [&](vector<int> &res) -> int{
		int v = 0;
		for(auto x : res){
			if(x < 0){
				while(1);
			}
			v = v * 10 + x;
		}
		return v;
	};
	vector<vector<int>>g(N);
	for(int i = 0; i < N; i++){
		vector<int>res;
		int t = i;
		while(t){
			res.push_back(t % 10);
			t /= 10;
		}
		while(res.size() < n)res.push_back(0);
		reverse(res.begin(), res.end());
		for(int j = 0; j < n; j++){
			for(int k = j; k < n; k++){
				for(int p = j; p <= k; p++){
					res[p] = (res[p] + 1) % 10;
				}
				g[i].push_back(get_num(res));
				for(int p = j; p <= k; p++){
					res[p] = (res[p] + 8) % 10;
				}
				g[i].push_back(get_num(res));
				for(int p = j; p <= k; p++){
					res[p] = (res[p] + 1) % 10;
				}
			}
		}
	}
	vector<int>d(N);
	auto bfs = [&](int s) -> void{
		d.assign(N, Max);
		vector<int>vs(N);
		d[s] = 0;
		vs[s] = 1;
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto v : g[u]){
				if(vs[v])continue;
				d[v] = d[u] + 1;
				vs[v] = 1;
				q.push(v);
			}
		}
	};
	vector<int>vis(N + 1 , 1);
	for(int i = 1; i <= m; i++){
		auto [s, lim] = a[i];
		bfs(s);
		for(int j = 0; j < N; j++){
			if(d[j] > lim){
				vis[j] = 0;
			}else if((lim - d[j]) % 2 == 1){
				if(lim == 1 && d[j] == 0)vis[j] = 0;
				if(n == 1)vis[j] = 0;
			}
		}
	}
	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		if(vis[i]){
			ans = i;
			//dbg(i);
			cnt++;
		}
	}
	if(cnt == 0){
		cout << "IMPOSSIBLE\n";
		return ;
	}
	if(cnt == 1){
		vector<int>res;
		while(ans){
			res.push_back(ans % 10);
			ans /= 10;
		}
		while(res.size() < n)res.push_back(0);
		reverse(res.begin(), res.end());
		for(auto x : res)cout << x;
		cout << '\n';
		return ;
	}
	cout << "MANY\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}