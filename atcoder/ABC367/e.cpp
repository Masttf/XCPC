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
    int K; cin >> K;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> ans(n + 1);
    vector f(64, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	f[0][i] = a[i];
    }
    for(int k = 1; k <= 63; k++){
    	for(int i = 1; i <= n; i++){
    		f[k][i] = f[k - 1][f[k - 1][i]];
    	}
    }
    for(int i = 1; i <= n; i++){
    	int now = i;
    	for(int j = 63; j >= 0; j--){
    		if(K >> j & 1){
    			now = f[j][now];
    		}
    	}
    	//dbg(i, now);
    	ans[i] = b[now];
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " \n"[i == n];
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