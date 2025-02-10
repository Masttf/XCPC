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
    int n, k; cin >> n >> k;
    int mx = 0, mi = n;
    vector<pair<int, int>> a(k + 1);
    for(int i = 1; i <= k; i++){
    	int l, r; cin >> l >> r;
    	a[i] = {l, r};
    	mx = max(mx, r - l + 1);
    	mi = min(mi, r - l + 1);
    }
    int cnt = 0;
    for(int i = 1; i <= k; i++){
    	auto [l, r] = a[i];
    	if(r - l + 1 == mx)cnt++;
    }
    if(cnt >= 2 && mi >= mx - 1){
    	cout << "IMPOSSIBLE\n";
    	return ;
    }
    vector<int> f(n + 1);
    int rt = -1;
    for(int i = 1; i <= k; i++){
    	auto [l, r] = a[i];
    	if(r - l + 1 == mx){
    		rt = l;
    		break;
    	}
    }
    int flag = 0;
    if(cnt == 1)flag = 1;
    for(int i = 1; i <= k; i++){
    	auto [l, r] = a[i];
    	if(r - l + 1 == mi && !flag){
    		f[l] = rt + 1;
    		flag = 1;
    	}else{
    		if(l != rt)f[l] = rt;
    	}
    	for(int j = l + 1; j <= r; j++){
			f[j] = j - 1;
		}
    }
    for(int i = 1; i <= n; i++){
    	cout << f[i] << " \n"[i == n];
    }
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