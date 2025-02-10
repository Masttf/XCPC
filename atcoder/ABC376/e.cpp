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
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first;
    }
    for(int i = 1; i <= n; i++){
    	cin >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    int ans = 1e18;
    priority_queue<int>q;
    int sum = 0;
    for(int i = 1; i < k; i++){
    	sum += a[i].second;
    	q.push(a[i].second);
    }
    for(int i = k; i <= n; i++){
    	ans = min(ans, (sum + a[i].second) * a[i].first);
    	if(!q.empty() && q.top() > a[i].second){
    		sum -= q.top();
    		q.pop();
    		q.push(a[i].second);
    		sum += a[i].second;
    	}
    }
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