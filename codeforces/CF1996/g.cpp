#include<bits/stdc++.h>
//#define int long long
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
struct node{
    int l, r;
    int val, tag;
};
void solve(){
    int n, m;cin >> n >> m;
    vector<node>tr(n * 140);
    vector<int>root(n * 4);
    int tot = 0;
    int now = 0;
    auto up = [&](int p, int l, int r) -> void{
        if(tr[p].tag){
            tr[p].val = r - l + 1;
        }else{
            int ls = tr[p].l;
            int rs = tr[p].r;
            if(l == r)tr[p].val = 0;
            else tr[p].val = tr[ls].val + tr[rs].val;
        }
    };
    auto updata = [&](auto self, int &u, int v, int l, int r,int x, int y, int val) -> void{
        if(u <= now){
            u = ++tot;
            tr[u] = tr[v];
        }
        if(x <= l && r <= y){
            tr[u].tag += val;
            up(u, l, r);
            //dbg(l, r, u, v, tr[u].val, tr[u].tag, tr[v].tag);
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, tr[u].l, tr[v].l, l, mid, x, y, val);
        if(y > mid)self(self, tr[u].r, tr[v].r, mid + 1, r, x, y, val);
        up(u, l, r);
        //dbg(l, r, u, v, tr[u].val, tr[u].tag);
    };

    int ans = n - 1;
    vector<vector<pair<int, int>>> tr2(n * 4);
    auto updata2 = [&](auto self, int l, int r, int x, int y, int ll, int rr, int p) -> void{
        if(x <= l && r <= y){
            tr2[p].push_back({ll, rr});
            //num++;
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, l, mid, x, y, ll, rr, p << 1);
        if(y > mid)self(self, mid + 1, r, x, y, ll, rr, p << 1 | 1);
        return ;
    };
    auto dfs = [&](auto self, int l, int r, int p) -> void{
        if(tr2[p].empty()){
            root[p] = root[p >> 1];
        }
        int temp = tot;
        now = tot;
        for(auto [x, y] : tr2[p]){
            //dbg(x, y, p, p >> 1, root[p], root[p >> 1]);
            updata(updata, root[p], root[p >> 1], 1, n, x, y, -1);
            if(x > 1){
                //dbg(1, x - 1);
                updata(updata, root[p], root[p >> 1], 1, n, 1, x - 1, 1);
            }
            //dbg(y + 1, n);
            updata(updata, root[p], root[p >> 1], 1, n, y + 1, n, 1);
        }
        
        if(l == r){
            ans = min(ans, tr[root[p]].val);
            //dbg(l , tr[root[p]].val);
            return ;
        }
        int mid = (l + r) >> 1;
        self(self, l, mid, p << 1);
        self(self, mid + 1, r, p << 1 | 1);
        //tot = temp;
        return ;
    };
    now = tot;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        //dbg(a, b - 1);  
        updata(updata, root[0], 0, 1, n, a, b - 1, 1);
        updata2(updata2, 1, n, a, b - 1, a, b - 1, 1);
    }
    dfs(dfs, 1, n, 1);
    cout << ans << '\n';

    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}