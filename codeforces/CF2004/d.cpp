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
constexpr int Max = 1e18;
void solve(){
    int n, q; cin >> n >> q;
    vector<array<int, 2>> color(n + 1);
    vector pos(50, vector<int>());
    for(int i = 1; i <= n; i++){
    	string s; cin >> s;
    	if(s[0] == 'B')color[i][0] = 2;
    	else if(s[0] == 'R')color[i][0] = 1;
    	else if(s[0] == 'G')color[i][0] = 3;
    	else color[i][0] = 4;
    	if(s[1] == 'B')color[i][1] = 2;
    	else if(s[1] == 'R')color[i][1] = 1;
    	else if(s[1] == 'G')color[i][1] = 3;
    	else color[i][1] = 4;
    	if(color[i][0] > color[i][1])swap(color[i][0],color[i][1]);
    	auto [l, r] = color[i];
    	pos[l * 10 + r].push_back(i);
    }
    auto get = [&](int x, int y, int t) -> int{
    	int res = Max;
    	int p = lower_bound(pos[t].begin(), pos[t].end(), x) - pos[t].begin();
    	if(p != pos[t].size()){
    		int v = pos[t][p];
    		if(v >= x && v <= y)return y - x;
    		res = min(res, v - x + v - y);
    	}
    	p--;
    	if(p >= 0){
    		int v = pos[t][p];
    		res = min(res, x - v + y - v);
    	}
    	return res;
    };
    for(int i = 1; i<= q; i++){
    	int x, y; cin >> x >> y;
    	if(x > y)swap(x, y);
    	set<int>s;
    	s.insert(color[x][0]);
    	s.insert(color[x][1]);
    	s.insert(color[y][0]);
    	s.insert(color[y][1]);
    	if(s.size() != 4){
    		cout << y- x << '\n';
    	}else{
    		int ans = Max;
    		for(int j = 0; j < 2; j++){
    			for(int k = 0; k < 2; k++){
    				int u = color[x][j];
    				int v = color[y][k];
    				if(u > v)swap(u, v);
    				ans = min(ans, get(x, y, u * 10 + v));
    			}
    		}
    		if(ans == Max)cout << -1 << '\n';
    		else cout << ans << '\n';
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}