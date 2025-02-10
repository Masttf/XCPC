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
void solve(){
	int n; cin >> n;
	vector<int> f(n + 1), g(n + 1);
	vector<int> du(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> f[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> g[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(f[i] < f[j] && g[i] < g[j]){
				du[j]++;
			}else{
				//du[i]++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		dbg(i, du[i]);
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