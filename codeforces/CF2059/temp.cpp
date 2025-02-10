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
    
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    vector b(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> b[i][j];

    vector<int> t(n, 0);

    for (int k = 0; k < n; ++k) {
        int max_t = 0;
        for (int candidate = 0; candidate <= m; ++candidate) {
            if (m - candidate < 0) {
                max_t = candidate;
                break;
            }
            bool ok = true;
            for (int i = 0; i < m - candidate; ++i) {
                if (a[k][i] != b[k][candidate + i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                max_t = candidate;
            }
        }
        t[k] = max_t;
    }

    for (int k = 1; k < n; ++k) {
        if (t[k] < t[k - 1]) {
            t[k] = t[k - 1];
        }
    }

    cout << t.back() << '\n';
    
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}