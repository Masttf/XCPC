
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
const int maxn = 105;
int f1[maxn][maxn][maxn], f2[maxn][maxn][maxn];
int a[maxn];

const int INF = 1e9;

// 必须填满
int dp2(int l, int r, int x){
    if ((r - l + 1) % 2 != 0) return -INF;
    if (r - l + 1 == 0) return 0;
    if (~f2[l][r][x]) return f2[l][r][x];
    int ans = -INF;
    if (a[l] % 2 == l % 2 and a[l] <= l and a[l] >= l - 2 * x){
        int cur = (l - a[l]) / 2;
        for(int j = l + 1; j <= r; j += 2){
            int t = dp2(l + 1, j - 1, cur);
            if (t < 0) continue;
            int s = t + 1;
            t = dp2(j + 1, r, x + s);
            if (t < 0) continue;
            s += t;
            ans = max(ans, s);
        }
    }
    return f2[l][r][x] = ans;
}

// 不一定要填满
int dp1(int l, int r, int x){
    if (l >= r) return 0;
    if (~f1[l][r][x]) return f1[l][r][x];
    int ans = 0;
    ans = max(dp1(l + 1, r, x), dp1(l, r - 1, x));
    for(int i = l; i < r; i++){
        int t = dp1(l, i, x);
        ans = max(ans, t + dp1(i + 1, r, x + t));
    }
    for(int j = l + 1; j <= r; j += 2){
        int t = dp2(l, j, x);
        if (t < 0) continue;
        int s = t;
        s += dp1(j + 1, r, x + t);
        ans = max(ans, s);
    }

    return f1[l][r][x] = ans;
}

int main(){


    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        memset(f1, -1, sizeof f1);
        memset(f2, -1, sizeof f2);
        cout << dp1(1, n, 0) << '\n';
    }

}