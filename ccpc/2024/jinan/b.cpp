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
    vector<int> cnt(5);
    for(int i = 1; i <= n; i++){
    	string s; cin >> s;
    	if(s[1] == 'D')cnt[1]++;
    	else if(s[1] == 'C')cnt[2]++;
    	else if(s[1] == 'H')cnt[3]++;
    	else cnt[4]++;
    }
    vector<int> t(10);
    for(int i = 1; i <= 6; i++){
    	cin >> t[i];
    }
    int ans = 0;
    vector<int> chose(5);
    int limit = n / 5;
    vector<int> back = t;
    // for(int i = 1; i <= 4; i++){
    // 	cout << cnt[i] << ' ';
    // }
    // cout << endl;
    auto dfs = [&](auto self, int now) -> void{
    	if(now == 5){
    		t = back;
    		int rem = 0;
    		for(int i = 1; i <= 4; i++){
    			if(chose[i] * 5 <= cnt[i]){
    				rem += cnt[i] - chose[i] * 5;
    			}
    		}
    		int ok = 1;
    		int use = 0;
    		if(t[5] && rem){
    			rem--;
    			use++;
    		}
    		// dbg(rem, use);
    		for(int i = 1; i <= 4; i++){
    			if(chose[i] * 5 <= cnt[i])continue;
    			int need = chose[i] * 5 - cnt[i];
				if(t[i]){
					int d = min(need, min(3ll, rem));
					need -= d;
					rem -= d;
				}
				if(t[6] && rem && need){
					t[6] = 0;
					rem--;
					need--;
				}
				if(need && use){
					need--;
					use--;
				}
				if(need)ok = 0;
    			
    		}
    		if(ok){
    			int sum = 0;
    			for(int i = 1; i <= 4; i++){
    				sum += chose[i];
    			}
    			// dbg(sum);
    			// for(int i = 1; i <= 4; i++){
    			// 	cout << chose[i] << ' ';
    			// }
    			// cout << endl;
    			ans = max(ans, sum);
    		}
    		return ;
    	}
    	for(int i = 0; i <= limit; i++){
    		chose[now] = i;
    		self(self, now + 1);
    		chose[now] = 0;
    	}
    };
    dfs(dfs, 1);
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