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
    int n, m, K; cin >> n >> m >> K;
    vector a(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    vector stMax(21, vector (n + 1, vector<int>(m + 1)));
    vector stMin(21, vector (n + 1, vector<int>(m + 1)));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            stMax[0][i][j] = stMin[0][i][j] = a[i][j];
        }
    }
    for(int k = 1; k <= 20; k++){
        for(int i = 1; i + (1ll << k) - 1 <= n; i++){
            for(int j = 1; j + (1ll << k) - 1 <= m; j++){
                stMax[k][i][j] = max({stMax[k - 1][i][j], stMax[k - 1][i + (1ll << (k - 1))][j], stMax[k - 1][i][j + (1ll << (k - 1))], stMax[k - 1][i + (1ll << (k - 1))][j + (1ll << (k - 1))]});
                stMin[k][i][j] = min({stMin[k - 1][i][j], stMin[k - 1][i + (1ll << (k - 1))][j], stMin[k - 1][i][j + (1ll << (k - 1))], stMin[k - 1][i + (1ll << (k - 1))][j + (1ll << (k - 1))]});
            }
        }
    }
    auto get = [&](int x, int y, int len) -> int{
        int d = __lg(len);
        int mx = max({stMax[d][x][y], stMax[d][x + len - (1ll << d)][y], stMax[d][x][y + len - (1ll << d)], stMax[d][x + len - (1ll << d)][y + len - (1ll << d)]});
        int mi = min({stMin[d][x][y], stMin[d][x + len - (1ll << d)][y], stMin[d][x][y + len - (1ll << d)], stMin[d][x + len - (1ll << d)][y + len - (1ll << d)]});
        return mx - mi;
    };
    auto check = [&](int len) -> bool{
        for(int i = 1; i + len - 1 <= n; i++){
            for(int j = 1; j + len - 1 <= m; j++){
                if(get(i, j, len) >= K)return true;
            }
        }
        return false;
    };
    int ans = -1;
    int l = 1, r = min(n, m);
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}