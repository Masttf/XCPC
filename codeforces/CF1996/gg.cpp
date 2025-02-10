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
    int val, tag;
};
void solve(){
    int n, m;cin >> n >> m;
    int ans = n - 1;
    vector<pair<int, int>>res(m + 1);
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        res[i] = {a, b};
    }
    vector<node>tr(n * 4);
    auto up = [&](int p, int l, int r) -> void{
        if(tr[p].tag){
            tr[p].val = r - l + 1;
        }else{
            if(l == r)tr[p].val = 0;
            else tr[p].val = tr[p << 1].val + tr[p << 1 | 1].val;
        }
    };
    auto updata = [&](auto self, int l, int r,int x, int y, int val, int p) -> void{
        if(x <= l && r <= y){
            tr[p].tag += val;
            up(p, l, r);
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, l, mid, x, y, val,p << 1);
        if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
        up(p, l, r);
    };
    vector stk(n + 1,vector<array<int, 3>>());
    for(int i = 1; i <= m; i++){
        auto [a, b] = res[i];
        updata(updata, 1, n, a, b - 1, 1, 1);
        stk[a].push_back({a, b - 1, -1});
        stk[b].push_back({a, b - 1, 1});
    }
    for(int i = 1; i <= n; i++){
        for(auto [a , b, c] : stk[i]){
            if(c == 1){
                updata(updata, 1, n, a, b, 1, 1);
                if(a > 1)updata(updata, 1, n, 1, a - 1, -1, 1);
                updata(updata, 1, n, b + 1, n, -1, 1);
            }else{
                updata(updata, 1, n, a, b, -1, 1);
                if(a > 1)updata(updata, 1, n, 1, a - 1, 1, 1);
                updata(updata, 1, n, b + 1, n, 1, 1);
            }
        }
        ans = min(ans, tr[1].val);
    }
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