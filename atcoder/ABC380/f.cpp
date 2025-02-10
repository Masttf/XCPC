#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
    int n, m, l; cin >> n >> m >> l;
    vector<set<pair<int, int>>> cnt(3);
    vector<int> p(n + m + l + 1);
    p[0] = 1;
    for(int i = 1; i <= n + m + l; i++){
        p[i] = p[i - 1] * 3;
    }
    array<int, 3> s = {0, 0, 0};
    vector<vector<int>> mp(2, vector<int>(p[n + m + l], -1));
    auto add = [&](int x, int y, int Id) -> void{
    	cnt[x].insert({y, Id});
        if(x == 2){
            s[0] += 2 * p[Id];
            s[1] += 2 * p[Id];
        }else{
            s[x ^ 1] += p[Id];
        }
    	
    };
    auto del = [&](int x, int y, int Id) -> void{
    	cnt[x].erase({y, Id});
    	if(x == 2){
            s[0] -= 2 * p[Id];
            s[1] -= 2 * p[Id];
        }else{
            s[x ^ 1] -= p[Id];
        }
    	return ;
    };
    int id = -1;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        id++;
        add(0, x, id);
    }
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        id++;
        add(1, x, id);
    }
    for(int i = 1; i <= l; i++){
        int x; cin >> x;
        id++;
        add(2, x, id);
    }

    auto dfs = [&](auto self, int t) -> int{
    	int ss = s[t];
        if(cnt[t].empty()){
            return 0;
        }
    	// dbg(ss, len);
    	if(mp[t][ss] != -1){
            return mp[t][ss];
        }
    	// dbg(t, statu[t], statu[2]);
    	int ok = 0;
    	set<pair<int, int>> r1, r2;
        r1 = cnt[t];
        r2 = cnt[2];
    	for(auto [x, Id] : r1){
    		if(ok)break;
    		del(t, x, Id);
            add(2, x, Id);
            if(!self(self, t ^ 1)) ok = 1;
    		for(auto [y, Id2] : r2){
    			if(ok)break;
    			if(y >= x)break;
                add(t, y, Id2);
                del(2, y, Id2);
    			if(!self(self, t ^ 1)) ok = 1;
    			del(t, y, Id2);
                add(2, y, Id2);
    		}
    		add(t, x, Id);
            del(2, x, Id);
    	}
    	return mp[t][ss] = ok;
    };
    if(dfs(dfs, 0) == 1){
    	cout << "Takahashi\n";
    }else{
    	cout << "Aoki\n";
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