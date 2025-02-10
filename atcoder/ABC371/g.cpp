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
constexpr int Max = 1e18;
void solve(){
    int n; cin >> n;
    vector<int>a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> prim, minp(n + 1);
	for(int i = 2; i <= n; i++){
		if(!minp[i]){
			prim.push_back(i);
			minp[i] = i;
		}
		for(auto p : prim){
			if(p * i > n)break;
			minp[i * p] = p;
			if(i % p == 0)break;
		}
	}
	vector<int>limt(n + 1, -1);
    vector<int>vis(n + 1);
    vector<int>res(n + 1);
	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		int now = i;
		vector<int>circle;
		while(!vis[now]){
			vis[now] = 1;
			circle.push_back(now);
			now = a[now];
		}
		const int sz = circle.size();
		int x = sz;
		vector<int>ps;
		while(x > 1){
			int val = 1;
			int p = minp[x];
			while(x % p == 0){
				x /= p;
				val *= p;
				ps.push_back(val);
			}
		}
		int k = -1;
		for(int j = 0; j < sz; j++){
			int ok = 1;
			for(auto p : ps){
				if(limt[p] != -1 && j % p != limt[p]){
					ok = 0;
				}
			}
			if(ok && (k == -1 || b[circle[j]] < b[circle[k]])) k = j;
		}
		for(int j = 0; j < sz; j++){
			res[circle[j]] = b[circle[(j + k) % sz]];
		}
		for(auto p : ps){
			limt[p] = k % p;
		}
	}
	for(int i = 1; i <= n; i++){
		cout << res[i] << " \n"[i == n];
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