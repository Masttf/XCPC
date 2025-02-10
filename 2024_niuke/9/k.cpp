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
constexpr int Max = 1e18;
void solve(){
	int n, k; cin >> n >> k;
	priority_queue<int>q;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		q.push(x);
	}
	int ans = q.top();
    if(k == 1){
        cout << ans << '\n';
        return ;
    }
	int cnt = 0;
	while(!q.empty()){
		int u = q.top();
		q.pop();
		cnt++;
		u /= k;
		if(u > 0)q.push(u);
		ans = min(ans, q.top() + cnt);
	}
	ans = min(ans, cnt);
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}