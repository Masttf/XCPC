#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n; cin >> n;
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> x[i] >> y[i];
    }
    vector<int> c(n + 1), k(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> k[i];
	
	vector<array<int, 3>> edge;
	for(int i = 1; i <= n; i++){
		edge.push_back({0, i, c[i]});
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j)continue;
			int w = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
			edge.push_back({i, j, w});
		}
	}
	sort(edge.begin(), edge.end(), [&](array<int, 3> &a, array<int, 3> &b) -> bool{
		return a[2] < b[2];
	});
	vector<int> f(n + 1);
	for(int i = 1; i <= n; i++) f[i] = i;
	auto find = [&](auto self, int x) -> int{
		return f[x] == x ? x : f[x] = self(self, f[x]);
	};
	int cnt = n;
	vector<int> ans1;
	vector<pair<int, int>> ans2;
	int res = 0;
	for(auto [u, v, w] : edge){
		if(!cnt)break;
		int X = find(find, u);
		int Y = find(find, v);
		if(X == Y)continue;
		cnt--;
		if(u == 0)ans1.push_back(v);
		else ans2.push_back({u, v});
		f[X] = Y;
		res += w;
	}
	cout << res << '\n';
	cout << ans1.size() << '\n';
	for(auto X : ans1) cout << X << ' ';
	cout << '\n';
	cout << ans2.size() << '\n';
	for(auto [X, Y] : ans2){
		cout << X << ' ' << Y << '\n';
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
/*
power station >= 1
bianli i zuowei power station
n (nlogm + m)
m = n^2 ? how
w = ki + kj
*/