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
    int a, b; cin >> a >> b;
    if(a > b)swap(a, b);
    int temp = (b - a);
    vector<pair<int, int>> pd;
    for(int i = 2; i * i <= temp; i++){
    	if(temp % i == 0){
    		int cnt = 0;
    		while(temp % i == 0){
    			cnt++;
    			temp /= i;
    		}
    		pd.push_back({i, cnt});
    	}
    }
    if(temp > 1){
    	pd.push_back({temp, 1});
    }
    map<pair<int, int>, int>mp;
    auto dfs = [&](auto self, int x, int d) -> int{
    	if(x == 1)return 0;
    	if(mp.count({x, d}))return mp[{x, d}];
    	int mi = x - 1;
    	for(auto &[p, y] : pd){
    		if(y == 0)continue;
    		y--;
    		int val = x / p * p;
    		mi = min(mi, self(self, x / p, d / p) + x - val + 1);
    		val += p;
    		mi = min(mi, self(self, (x + p - 1) / p, d / p) + val - x + 1);
    		y++;
    	}
    	return mp[{x, d}] = mi;
    };
    cout << dfs(dfs, a, b - a) << '\n';
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