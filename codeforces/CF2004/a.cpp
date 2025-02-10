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
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a.begin(), a.end());
	int ok = 0;
	vector<int>vis(200);
	vector<int>dis(n + 1, Max);
	for(int i = 1; i <= n; i++){
		vis[a[i]] = 1;
		if(i != 1)dis[i] = min(dis[i], a[i] - a[i - 1]);
		if(i != n)dis[i] = min(dis[i], a[i + 1] - a[i]); 
	}

	for(int i = 0; i <= 101; i++){
		if(vis[i])continue;
		int f = 1;
		for(int j = 1; j <= n; j++){
			int d = abs(a[j] - i);
			if(d >= dis[j])f = 0;
		}
		if(f)ok = 1;
	}
    if(ok)cout << "Yes\n";
	else cout << "No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}