#include<bits/stdc++.h>
// #define int long long
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
constexpr int maxn = 4e7 + 5, N = 5e5 + 5;
struct node{
    int lson, rson;
    int val;
}tr[maxn];
int father[maxn], who[maxn], val[N], root[N];
pair<int, int> op[N];
void solve(){
    int n; cin >> n;
    int L = 1, R = 1e9;
    map<int, int> mp;
    int tot = 1;
    int rt = n + 1;
    int id = 0;
    auto newNode = [&](int l, int r, int f) -> int{
        tr[++tot].val = r - l + 1;
        father[tot] = f;
        return tot;
    };
    auto update = [&](auto self, int l, int r, int x, int &p, int f) -> void{
        if(!p) p = newNode(l, r, f);
        if(l == r){
            mp[x] = p;
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, l, mid, x, tr[p].lson, p);
        else self(self, mid + 1, r, x, tr[p].rson, p);
    };
    
    auto split = [&](auto self, int l, int r, int x, int &u, int &v ,int f) -> void{
        if(!u) u = newNode(l, r, f);
        assert(u != 1);
        if(l == r){
            v = u;
            u = 1;
            return ;
        }
        int mid = (l + r) >> 1;
        v = ++tot;
        tr[v].lson = 1;
        tr[v].rson = 1;
        if(x == 0)return ;
        int val = tr[tr[u].lson].val;
        if(!tr[u].lson)val = mid - l + 1;
        if(x <= val){
            self(self, l, mid, x, tr[u].lson, tr[v].lson, u);
            father[tr[v].lson] = v;
        }else{
            swap(tr[v].lson, tr[u].lson);
            father[tr[v].lson] = v;
            self(self, mid + 1, r, x - val, tr[u].rson, tr[v].rson, u);
            father[tr[v].rson] = v;
        }
        tr[u].val = tr[tr[u].lson].val + tr[tr[u].rson].val;
        if(!tr[u].lson) tr[u].val += mid - l + 1;
        if(!tr[u].rson) tr[u].val += r - mid;
        tr[v].val = tr[tr[v].lson].val + tr[tr[v].rson].val;
        if(!tr[v].lson) tr[v].val += mid - l + 1;
        if(!tr[v].rson) tr[v].val += r - mid;
    };
    auto merge = [&](auto self, int &x, int y) -> void{
        if(!x)return ;
        if(!y){
            x = 0;
            return ;
        }
        if(x == 1 || y == 1){
            if(y != 1) x = y;
            return ;
        }
        tr[x].val += tr[y].val;
        father[tr[y].lson] = x;
        father[tr[y].rson] = x;
        self(self, tr[x].lson, tr[y].lson);
        self(self, tr[x].rson, tr[y].rson);
    };

    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        op[i] = {x, y};
        if(x == 3){
            update(update, L, R, y, root[rt], 0);
        }
    }
    for(int i = 1; i <= n; i++){
        auto [ty, x] = op[i];
        if(ty == 1){
            id++;
            x = min(x, tr[root[rt]].val);
            split(split, L, R, x, root[rt], root[id], 0);
            who[root[id]] = id;
        }else if(ty == 2){
            merge(merge, root[rt], root[x]);
        }else{
            int now = mp[x];
            while(father[now]){
                now = father[now];
            }
            if(now == root[rt]){
                cout << 0 << '\n';
            }else{
                cout << who[now] << '\n';
            }
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
值域很大怎么做？
动态开点 1e9， 有办法缩点嘛？
*/