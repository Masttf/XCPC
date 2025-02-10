#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int Max = 1e18;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    int ok = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] % 2 != a[1] % 2)ok = 0;
	}
	if(!ok){
		cout << -1 << '\n';
		return ;
	}
	cout << 40 << '\n';
	for(int i = 1; i <= 40; i++){
		int mi = Max, mx = 0;
		for(int j = 1;j <= n; j++){
			mi = min(mi, a[j]);
			mx = max(mx, a[j]);
		}
		int res = (mx + mi) / 2;
		cout << res << ' ';
		for(int j = 1;j <= n; j++){
			a[j] = abs(a[j] - res);
		}
	}
	cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}