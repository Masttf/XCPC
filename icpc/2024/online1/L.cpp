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
constexpr int maxn = 2e3 + 5;
void solve(){
    int n, l, q; cin >> n >> l >> q;
    vector t(l + 1, vector<int> (n + 1));
    for(int i = 1; i <= l; i++){
    	string s; cin >> s;
    	for(int j = 0; j < 2 * n; j += 2){
    		t[i][j / 2 + 1] = (s[j] - 48) * 50 + s[j + 1] - 48;
    	}
    }
    vector Q(l + 1, vector<array<int, 3>>());
    for(int i = 1; i <= q; i++){
    	string s; cin >> s;
    	array<int, 3> res;
    	for(int j = 0; j < 6; j += 2){
    		res[j / 2] = (s[j] - 48) * 50 + s[j + 1] - 48;
    	}
    	Q[res[2]].push_back({res[0], res[1], i});
    	//dbg(res[0], res[1], res[2]);
    }
    // for(int i = 1; i <= l; i++){
    // 	for(int j = 1; j <= n; j++){
    // 		cout << t[i][j] << ' ';
    // 	}
    // 	cout << '\n';
    // }
    // cout << endl;
    vector a(l + 1, vector<pair<int, int>>());
    for(int i = 1; i <= l; i++){
    	vector<int>cnt(n + 1);
    	int lim = 0;
    	for(int j = 1; j <= n; j++){
    		if(lim == 2)break;
    		cnt[t[i][j]]++;
    		if(cnt[t[i][j]] == 2)lim++;
    		else if(cnt[t[i][j]] >= 3)lim = 2;
    	}
    	if(lim == 0){
    		for(int j = 1; j <= n; j++){
    			if(j == t[i][j])continue;
    			a[i].push_back({j, t[i][j]});
    		}
    	}else if(lim == 1){
    		int now = 1;
    		while(cnt[now])now++;
    		for(int j = 1; j <= n; j++){
    			if(cnt[t[i][j]] == 2){
    				a[i].push_back({j, now});
    			}
    		}
    	}
    }

    vector<int> ans(q + 1);
    vector<bitset<maxn>> res(n + 1);
    vector<bitset<maxn>> f(n + 1);
    for(int i = 1; i <= n; i++){
    	res[i][i] = 1;
        f[i][i] = 1;
    }
    for(int i = 0; i <= l; i++){
    	for(auto [u, v] : a[i]){
            bitset<maxn> r1 = f[v];
            r1.flip();
            r1 &= f[u];
            bitset<maxn> r2 = res[u];
            r2.flip();
            r2 &= res[v];
            for(int j = r1._Find_first(); j <= n; j = r1._Find_next(j)){
                res[j] |= res[v];
            }
            for(int j = r2._Find_first(); j <= n; j = r2._Find_next(j)){
                f[j] |= f[u];
            }
    	}
    	for(auto [a, b, id] : Q[i]){
    		ans[id] = res[a][b];
    	}
    }
    for(int i = 1; i <= q; i++)cout << ans[i];
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}