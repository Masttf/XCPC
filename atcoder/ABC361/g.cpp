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
constexpr int inf = 1e9;
void solve(){
    int n; cin >> n;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++){
    	int x, y; cin >> x >> y;
    	mp[x].push_back(y);
    	mp[x - 1];
    	mp[x + 1];
    }
    vector<array<int, 3>> seg;
    for(auto [x, y] : mp){
    	if(y.empty()){
    		seg.push_back({x, -inf, inf});
    		continue;
    	}
    	sort(y.begin(), y.end());
    	seg.push_back({x, -inf, y[0] - 1});
    	for(int i = 0; i < y.size() - 1; i++){
    		if(y[i] + 1 <= y[i + 1] - 1)
    			seg.push_back({x, y[i] + 1, y[i + 1] - 1});
    	}
    	seg.push_back({x, y.back() + 1, inf});
    }
    int cnt = seg.size();
    vector<int> f(cnt);
    for(int i = 0; i < cnt; i++) f[i] = i;
    auto find = [&](auto self, int x) -> int {
    	return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    auto merge = [&](int a, int b) -> void{
    	int fa = find(find, a);
    	int fb = find(find, b);
    	if(fa == fb)return ;
    	f[fa] = fb;
    	return ;
    };
    for(int i = 0; i < cnt; i++){
    	if(seg[i][1] == -inf && seg[i][2] == inf){
    		merge(i, 0);
    	}
    }
    for(int i = 0, j = 0; i < cnt; i++){
    	while(j < cnt && (seg[j][0] < seg[i][0] + 1 || seg[j][2] < seg[i][1])){
    		j++;
    	}
    	while(j < cnt && seg[j][0] == seg[i][0] + 1 && seg[j][1] <= seg[i][2]){
    		merge(i, j);
    		j++;
    	}
    	j--;
    }
    int ans = 0;
    for(int i = 1; i < cnt; i++){
    	if(find(find, i) != find(find, 0)){
    		ans += seg[i][2] - seg[i][1] + 1;
    	}
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}