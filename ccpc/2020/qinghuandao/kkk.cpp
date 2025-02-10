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

const int maxn = 1e5 + 5;
struct node {
    int w,v;
    bool operator < (const node & b)const {
        return w < b.w;
    }
};
vector<node>t[maxn];
int dep[maxn],deep[maxn];

void dfs(int u,int f) {
    int mx = dep[u];
    for (auto i : t[u]) {
        if (i.v == f) continue;
        dep[i.v] = dep[u] + 1;
        dfs(i.v,u);
        i.w = deep[i.v];
        mx = max(mx,deep[i.v]);
    }
    deep[u] = mx;
    sort(t[u].begin(),t[u].end());
}

int d,pre,ans;

void dfs1(int u,int f) {
    if (!t[u].size()) {
        if (pre == -1) ans += dep[u] ;
        else ans += min(dep[u],d);
        d = 0;
        pre = u;       
        //dbg(u,ans);
        return ; 

    }
    for (auto i : t[u]) {
        if (i.v == f) continue;
        if (pre != -1) d++;
        dfs1(i.v,u);
        if (pre != -1) d++;
    }
}

void solve(){
    ans = 0,pre = -1,d = 0;
    int n;cin >> n;
    for (int i = 1;i <= n;i++) {
        t[i].clear();
        dep[i] = deep[i] = 0;
    }
    for (int i = 2;i <= n;i++) {
        int x;cin >> x;
        t[x].push_back({0,i});
    }
    //dep[1] = 1;
    dfs(1,0);
    //for (int i = 1;i <= n;i++) dbg(i,dep[i]);
    dfs1(1,0);
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    }
    return 0;
}