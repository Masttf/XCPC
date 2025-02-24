#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \ 
}while(0)
void err(){
	cout << endl << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>>edge(m + 1);
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		edge[i] = {u, v};
	}
	int block = (m + n - 2) / (n - 1);
	vector<vector<int>> f(block + 1, vector<int>(n + 1));
	vector<int> cnt(block + 2, n - 1);
	for(int i = 1; i <= block; i++){
		for(int j = 1; j <= n; j++)f[i][j] = j;
	}
	auto find = [&](auto self, int id, int x) -> int{
		return f[id][x] == x ? x : f[id][x] = self(self, id, f[id][x]);
	};
	auto merge = [&](int id, int a, int b) -> void{
		int fa = find(find, id, a);
		int fb = find(find, id, b);
		if(fa == fb)return ;
		cnt[id]--;
		f[id][fa] = fb;
		return ;
	};
	auto check = [&](int id, int a, int b) -> bool{
		int fa = find(find, id, a);
		int fb = find(find, id, b);
		if(fa == fb)return true;
		else return false;
	};
	vector<int>bl(m + 1);
	for(int i = 1; i <= m; i++){
		int u = edge[i].first;
		int v = edge[i].second;
		int ans = 0;
		int l = 1, r = block;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid, u, v)){
				ans = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		ans++;
		//dbg(ans);
		bl[i] = min(block + 1, ans);
		if(ans <= block)merge(ans, u, v);
	}
	for(int i = 1; i <= m; i++){
		if(!cnt[bl[i]]){
			cout << bl[i] << ' ';
		}else cout << -1 << ' ';
	}
	cout << '\n';
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
/*
1
3 3
1 2
2 3
3 1

1
3 3
1 2
2 1
2 1
*/