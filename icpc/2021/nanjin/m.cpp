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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n == 1){
    	cout << a[1] << '\n';
    	return ;
    }
    int ok1 = 0, ok2 = 0, ok3 = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > 0)ok1 = 1;
		else if(a[i] < 0)ok2 = 1;
		else ok3 = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += abs(a[i]);
	}
	int mi = 1e9;
	for(int i = 1; i <= n; i++){
		mi = min(mi, abs(a[i]));
	}
	// dbg(ans, mi);
	if((ok1 && ok2) || ok3){

	}else ans -= 2 * mi;
	cout << ans << '\n';
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