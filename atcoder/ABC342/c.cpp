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
    string s; cin >> s;
    int q; cin >> q;
    vector<vector<int>> pos(30);
    s = ' ' + s;
    for(int i = 1; i <= n; i++){
    	pos[s[i] - 'a'].push_back(i);
    }
    for(int i = 1; i <= q; i++){
    	char x, y; cin >> x >> y;
    	if(x == y)continue;
    	int xx = x - 'a';
    	int yy = y - 'a';
    	if(pos[yy].size() < pos[xx].size()){
    		swap(pos[xx], pos[yy]);
    	}
    	for(auto c : pos[xx]){
    		pos[yy].push_back(c);
    	}
    	pos[xx].clear();
    }
    vector<char> ans(n + 1);
    for(int i = 0; i < 26; i++){
    	for(auto x : pos[i]){

    		ans[x] = i + 'a';
    		// dbg(i, x);
    	}
    }
    for(int i = 1; i <= n; i++){
    	cout << ans[i];
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