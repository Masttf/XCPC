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
    int n, k, q; cin >> n >> k >> q;
    vector<pair<int, int>> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    	a[i].first--;
    	sum += a[i].second;
    }
    vector<int> ft(n + 1), nt(n + 1);
    int time = 0;
    for(int i = 1; i <= n; i++){
    	time = time + a[i].second;
    	time = max(time, a[i].first + a[i].second);
    	ft[i] = time;
    }
    int ok = 0;
    for(int i = 1; i <= n; i++){
    	time = time + a[i].second;
    	time = max(time, k + a[i].first + a[i].second);
    	if(time == k + a[i].first + a[i].second) ok = 1;
    	nt[i] = time;
    }
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
    	int tot = 0;
    	if(x == 1)tot = ft[y];
    	else if(x == 2)tot = nt[y];
    	else if(!ok){
    		tot = (x - 2) * sum + nt[y];
    	}else{
    		tot = (x - 2) * k + nt[y];
    	}
    	int sx = tot / k + 1;
    	int sy = tot % k;
    	if(sy == 0){
    		sx--;
    		sy = k;
    	}
    	cout << sx << ' ' << sy << '\n'; 
    }
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