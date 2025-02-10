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
	int k; cin >> k;
	vector<array<int, 4>> a(k + 1);
	for(int i = 1; i <= k; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i] = {x1, y1, x2, y2};
	}
	a[0] = {1, 1, n, m};
	vector res(n + 1, vector<array<int, 4>>(m + 1));
	vector<vector<pair<int, int>>> q1(n + 1), q2(n + 1), q3(m + 1), q4(m + 1);
	for(int i = 0; i <= k; i++){
		auto [x1, y1, x2, y2] = a[i];
		q1[x1].push_back({y1, y2});
		q2[x2].push_back({y1, y2});
		q3[y1].push_back({x1, x2});
		q4[y2].push_back({x1, x2});
	}
	for(int i = 1; i <= n; i++){
		vector<int>d(m + 2);
		for(auto [y1, y2] : q1[i]){
			d[y1]++;
			d[y2 + 1]--;
		}
		for(int j = 1; j <= m; j++)d[j] += d[j - 1];
		for(int j = 1; j <= m; j++){
			if(d[j]){
				res[i][j][0] = i;
			}else res[i][j][0] = res[i - 1][j][0];
		}
	}

	for(int i = n; i >= 1; i--){
		vector<int>d(m + 2);
		for(auto [y1, y2] : q2[i]){
			d[y1]++;
			d[y2 + 1]--;
		}
		for(int j = 1; j <= m; j++)d[j] += d[j - 1];
		for(int j = 1; j <= m; j++){
			if(d[j]){
				res[i][j][2] = i;
			}else res[i][j][2] = res[i + 1][j][2];
		}
	}

	for(int i = 1; i <= m; i++){
		vector<int>d(n + 2);
		for(auto [x1, x2] : q3[i]){
			d[x1]++;
			d[x2 + 1]--;
		}
		for(int j = 1; j <= n; j++)d[j] += d[j - 1];
		for(int j = 1; j <= n; j++){
			if(d[j])res[j][i][1] = i;
			else res[j][i][1] = res[j][i - 1][1];
		}
	}

	for(int i = m; i >= 1; i--){
		vector<int>d(n + 2);
		for(auto [x1, x2] : q4[i]){
			d[x1]++;
			d[x2 + 1]--;
		}
		for(int j = 1; j <= n; j++)d[j] += d[j - 1];
		for(int j = 1; j <= n; j++){
			if(d[j])res[j][i][3] = i;
			else res[j][i][3] = res[j][i + 1][3];
		}
	}
	int ans = n * m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			auto [x1, y1, x2, y2] = res[i][j];
			//dbg(i, j, x1, y1, x2, y2);
			if(x1 == i && y1 == j)
				ans = min(ans, (x2 - x1 + 1)*(y2 - y1 + 1));
		}
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}