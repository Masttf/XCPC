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
void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>>g(n + 1);
    vector<int>p(n + 1);
    for(int i = 2; i <= n; i++){
    	cin >> p[i];
        g[p[i]].push_back(i);
    }
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int>sz(n + 1);
    auto dfs = [&](auto self, int now) -> void{
        sz[now] = 1;
        for(auto v :g[now]){
            self(self, v);
            sz[now] += sz[v];
        }
    };
    dfs(dfs, 1);
    set<int>s;
    auto check = [&](int x) -> bool{
    	if(x <= 0)return true;
        int siz = 1;
        int now = x;
        for(int i = 1; i <= g[x].size(); i++){
            if(pos[now] + siz > n)return false;
            int v = a[pos[now] + siz];
            if(p[v] != x)return false;
            now = v;
            siz = sz[v];
        }
    	return true;
    };
    for(int i = 1; i <= n; i++){
    	if(!check(i)){
    		s.insert(i);
    	}
    }
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
    	swap(pos[a[x]], pos[a[y]]);
    	swap(a[x], a[y]);
    	s.insert(a[x]);
    	s.insert(a[y]);
    	s.insert(p[a[x]]);
    	s.insert(p[a[y]]);
        if(check(a[x])){
            s.erase(a[x]);
        }
        if(check(a[y])){
            s.erase(a[y]);
        }
        if(check(p[a[x]])){
            s.erase(p[a[x]]);
        }
        if(check(p[a[y]])){
            if(s.count(p[a[y]]))s.erase(p[a[y]]);
        }
    	if(s.empty())cout << "Yes\n";
    	else cout << "No\n";
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