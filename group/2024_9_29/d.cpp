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
int res[7][7] = {{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 2, 3, 4, 5},
				{0, 0, 6, 15, 28, 45, 66},
				{0, 0, 15, 52, 143, 350, 799},
				{0, 0, 28, 143, 614, 2431, 9184},
				{0, 0, 45, 350, 2431, 16000, 0},
				{0, 0, 66, 799, 9184, 0, 0}
				};
void solve(){
    int n, m; cin >> n >> m;
    cout << res[n][m] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}