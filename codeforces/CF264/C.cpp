#include <bits/stdc++.h>

using namespace std;
#define dbg(x...) \
    do { \
        cout << #x << " -> "; \
        err(x); \
    } while (0)

void err() {
    cout << endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
    cout << arg << ' ';
    err(args...);
}

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
const ll inf = 1e18;

int v[N], c[N];
ll mx[N];

struct node{
    ll val;
    int color;

    bool operator < (const node &p) const{
        return val > p.val;
    }
}dp[2], pd[3];

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    while(q--){
        int a, b;
        cin >> a >> b;
        int cd = 0;
        for(int i = 1; i <= n; i++) mx[i] = -inf;
        for(int i = 1; i <= n; i++){
            int cp = 0;
            ll res = mx[c[i]];
            for(int j = 0; j < cd; j++){
                auto [val, color] = dp[j];
                ll y = val;
                if(color == c[i]){
                    y += 1ll * v[i] * a;
                }else{
                    y += 1ll * v[i] * b;
                    pd[cp++] = {val, color};
                }
                res = max(res, y);
            }
            res = max({res, mx[c[i]] + 1ll * v[i] * a, 1ll * v[i] * b});
            mx[c[i]] = res;
            pd[cp++] = {res, c[i]};
            sort(pd, pd + cp);
            cd = min(2, cp);
            for(int j = 0; j < cd; j++) dp[j] = pd[j];
        }
        cout << max(dp[0].val, 0ll) << "\n";
    }
}

int main() {
    int T = 1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    while (T--) solve();
    return 0;
}