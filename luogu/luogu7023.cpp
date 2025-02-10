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
    int mx = *max_element(a.begin() + 1, a.end());
	vector<int> cnt(mx + 1), vis(mx + 1);
	for(int i = 1; i <= n; i++){
		cnt[a[i]]++;
	}
	for(int i = mx; i >= 1; i--){
		if(!cnt[i])continue;
		for(int j = 2 * i; j <= mx; j += i){
			if(cnt[j]){
				vis[i] = 1;
			}
		}
	}
	int tot = 0;
	for(int i = 1; i <= mx; i++){
		if(cnt[i])tot++;
	}
	vector<int>ans(n + 1, n + 1);
	ans[0] = tot;
	ans[n] = 1;
	priority_queue<int, vector<int>, greater<int>> q, q2;
	for(int i = 1; i <= mx; i++){
		if(cnt[i]){
			q.push(cnt[i]);
			if(vis[i])q2.push(cnt[i]);
		}
	}
	int sum = 0;
	for(int i = 1, j = 0; i < n; i++){
		while(!q.empty() && sum + q.top() <= i){
			sum += q.top();
			q.pop();
			j++;
		}
		ans[i] = min(ans[i], tot - j + 1);
	}
	sum = 0;
	for(int i = 1, j = 0; i < n; i++){
		while(!q2.empty() && sum + q2.top() <= i){
			sum += q2.top();
			q2.pop();
			j++;
		}
		ans[i] = min(ans[i], tot - j);
	}
	for(auto x : ans){
		cout << x << ' ';
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