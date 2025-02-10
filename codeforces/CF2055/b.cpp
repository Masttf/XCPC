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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int cnt = 0;
	int d = 1e18;
	int need = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] < b[i])cnt++, need = b[i] - a[i];
		else d = min(d, a[i] - b[i]);
	}
	// dbg(cnt, d, need);
	if(cnt == 0)cout << "Yes\n";
	else{
		if(cnt == 1 && d >= need)cout << "Yes\n";
		else cout << "No\n";
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