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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> p;
    p.push_back(0);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	int x = a[i];
    	while(x){
    		p.push_back(x);
    		x /= 2;
    	}
    }
    int ans = 1e18;
    auto run = [&](int target) -> void{
    	vector<int>temp;
    	for(int i = 1; i <= n; i++){
    		int now = abs(a[i] - target);
    		int cnt = 0;
    		int x = a[i];
    		while(x){
    			cnt++;
    			x /= 2;
    			now = min(now, cnt + abs(target - x));
    		}
    		temp.push_back(now);
    	}
    	sort(temp.begin(), temp.end());
    	int sum = 0;

    	for(int i = 0; i < n - m; i++){
    		sum += temp[i];
    	}
    	ans = min(ans, sum);
    };
    for(auto x : p){
    	run(x);
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