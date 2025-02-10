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
void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector<pair<int, int>>b(m + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
    sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());
	int ans = 0;
	priority_queue<int>q;
	for(int i = 1, j = 1; i <= n; i++){
		while(j <= m && b[j].first < a[i]){
			q.push(b[j].second - b[j].first);
			j++;
		}
		if(q.empty() || a[i] + q.top() < 0)continue;
		ans += a[i] + q.top();
		q.pop();
		q.push(-a[i]);
	}
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