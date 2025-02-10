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
    vector<int> limit(n + 1);
    for(int i = 1; i <= n; i++) cin >> limit[i];
    vector<int> ans(n + 1);
    auto dfs = [&](auto self, int now, int sum) -> void{
    	if(now == n + 1){
    		//dbg(sum);
    		if(sum % k == 0){
    			for(int i = 1; i <= n; i++){
    				cout << ans[i] << ' ';
    			}
    			cout << '\n';
    		}
    		return ;
    	}
    	for(int i = 1; i <= limit[now]; i++){
    		ans[now] = i;
    		self(self, now + 1, sum + i);
    	}
    	return ;
    };
    dfs(dfs, 1, 0);
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