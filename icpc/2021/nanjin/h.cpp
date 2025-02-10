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
vector <int> t[maxn];
int a[maxn],b[maxn],dp[maxn][3];


//op1: dp[v1][0] + dp[u][2] - dp[v][0]
//op2: dp[v1][0] + a[v2] + dp[u][2] - dp[v][0]
constexpr int inf = 1e18;
void dfs(int u,int f) {
	int ok = 0;
	int mx1 = -inf,mx2 = -inf,sum = 0;
	for (auto i : t[u]) {
		if (i == f) continue;
		ok = 1;
		dfs(i,u);
		sum += dp[i][0];
		if (a[i] + dp[i][1] - dp[i][0] >= mx1) {
			mx2 = mx1;
			mx1 = a[i] + dp[i][1] - dp[i][0];
		}
		else {
			if (a[i] + dp[i][1] - dp[i][0] >= mx2) mx2 = a[i] + dp[i][1] - dp[i][0];
		}
	}
	if (!ok) {
		dp[u][0] = 0;
		dp[u][1] = 0;
		dp[u][2] = a[u];
		return ;
	}
	dp[u][1] = sum;
	int mx = 0;
	//dbg(u,mx1,mx2,sum);
	for (auto i : t[u]) {
		if (i == f) continue;
		mx = max(mx,sum - dp[i][0] + dp[i][2]);
		int now_mx = mx1;
		if (a[i] + dp[i][1] - dp[i][0] == mx1) now_mx = mx2;
		if(now_mx == -inf)continue;
		if (b[i] == 3) mx = max(mx,sum - dp[i][0] + dp[i][2] + now_mx);
	}
	dp[u][0] = mx;
	dp[u][2] = mx + a[u];
	//dbg(u,dp[u][0],dp[u][1],dp[u][2]);
}

void solve(){
    int n;cin >> n;
    for (int i = 1;i <= n;i++) {
		t[i].clear();
		dp[i][0] = dp[i][1] = dp[i][2] = 0;
    }
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    for (int i = 1;i < n;i++) {
    	int u,v;cin >> u >> v;
    	t[u].push_back(v);
    	t[v].push_back(u);
    }
    dfs(1,0);
    cout << dp[1][2] << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;  cin >> t;
    while(t--)solve();
    return 0;
}