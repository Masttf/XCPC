#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}

vector<int> ans(10005, -1);
array<int, 4> get(int x) {
	return {x / 1000 % 10, x / 100 % 10, x / 10 % 10, x % 10};
}
int rget(const array<int, 4> &x) {
	return x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
}
void bfs() {
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	while(!q.empty()) {
		auto [x, dis] = q.front();
		q.pop();
		if(ans[x] == -1) ans[x] = dis;
		else continue;
		
		array<int, 4> tmp = get(x);
		for(int i = 0; i < 4; ++i) {
			for(int j = i; j < 4; ++j) {
				tmp[j] = (tmp[j] + 1) % 10;
				q.emplace(rget(tmp), dis + 1);
			}
			for(int j = i; j < 4; ++j) {
				tmp[j]--;
				if(tmp[j] < 0) tmp[j] += 10;
			}
			for(int j = i; j < 4; ++j) {
				tmp[j]--;
				if(tmp[j] < 0) tmp[j] += 10;
				q.emplace(rget(tmp), dis + 1);
			}
			for(int j = i; j < 4; ++j) {
				tmp[j] = (tmp[j] + 1) % 10;
			}
		}
	}
	// for(int i = 1; i <= 9999; ++i) cout << i << ' ' << ans[i] << '\n';
}

void solve(){
	int a, b;
	cin >> a >> b;
	auto A = get(a);
	auto B = get(b);
	for(int i = 0; i < 4; ++i) {
		B[i] -= A[i];
		while(B[i] < 0) B[i] += 10;
	}
	cout << ans[rget(B)] << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	bfs();
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}