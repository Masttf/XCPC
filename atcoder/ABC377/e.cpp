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
    int n, K; cin >> n >> K;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> f(n + 1);
	for(int i = 1; i <= n; i++){
		f[a[i]] = i;
	}
    vector st(61, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		st[0][i] = f[i];
	}
	for(int k = 1; k <= 60; k++){
		for(int i = 1; i <= n; i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	vector<int> ans(n + 1);
	for(int i = 1; i <= n; i++){
		int now = i;
		for(int j = 60; j >= 0; j--){
			if(K >> j & 1){
				now = st[j][now];
			}
		}
		ans[now] = a[i];
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
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