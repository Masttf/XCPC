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
    int k; cin >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k == 1){
    	int ans = max(a[1], a[n]);
    	int mx = 0;
    	if(a[1] > a[n]){
    		for(int i = 2; i <= n; i++)mx = max(mx, a[i]);
    	}else{

    		for(int i = 1; i < n; i++)mx = max(mx, a[i]);
    	}
    	cout << ans + mx << '\n';
    }else{
    	int ans = 0;
    	sort(a.begin() + 1, a.end());
    	for(int i = n - k; i <= n; i++){
    		ans += a[i];
    	}
    	cout << ans << '\n';
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
/*
值最大
*/