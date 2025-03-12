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
constexpr int maxn = 105;
int dp[maxn][maxn][2 * maxn];
constexpr int inf = 1e9;
template<class T, 
    class Cmp = std::less<T>>
struct ST{
    int n, k;
    const Cmp cmp = Cmp();
    vector<vector<T>> st;
    ST(){}
    ST(const vector<T> &a){
        init(a);
    }
    void init(const vector<T> &a){
        n = a.size() - 1;
        k = __lg(n);
        st.resize(k + 1, vector<T>(n + 1));
        for(int i = 1; i <= n; i++){
            st[0][i] = a[i];
        }
        for(int s = 1; s <= k; s++){
            for(int i = 1; i + (1 << s) <= n + 1; i++){
                st[s][i] = min(st[s - 1][i], st[s - 1][i + (1 << (s - 1))], cmp);
            }
        }
    }
    T get(int l, int r){
        int d = __lg(r - l + 1);
        return min(st[d][l], st[d][r - (1 << d) + 1], cmp);
    }
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
    	if(i >= a[i] && (i - a[i]) % 2 == 0){
    		a[i] = (i - a[i]) / 2;
    	}else a[i] = -1;
    }
    for(int i = 0; i <= n; i++){
    	for(int j = 0; j <= n; j++){
    		for(int k = 0; k <= n; k++){
    			dp[i][j][k] = 0;
    		}
    	}
    }
    ST<int, greater<int>> st(a);
    // dbg(dp[1][2][0]);
    for(int len = 2; len <= n; len++){
    	for(int i = 1; i + len <= n + 1; i++){
    		int l = i, r = i + len - 1;
    		for(int k = 0; k <= n; k++){
    			dp[l][r][k] = max(dp[l + 1][r][k], dp[l][r - 1][k]);
    			if(len % 2 == 0 && dp[l + 1][r - 1][k] == len / 2 - 1){
                    if(a[l] >= 0 && k >= a[l] && (l + 1 > r - 1 || st.get(l + 1, r - 1) <= a[l])){
						dp[l][r][k] = len / 2;
			    	}
    			}

    			for(int j = l; j < r; j++){
                    int h = min(n, dp[l][j][k] + k);
    				dp[l][r][k] = max(dp[l][r][k], dp[l][j][k] + dp[j + 1][r][h]);
    			}
                // dbg(l, r, k, dp[l][r][k]);
    		}
            dbg(l, r, dp[l][r][n]);
    	}
    }
    cout << dp[1][n][0] << '\n';
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
/*
最多操作几次？
删后面对前面没有影响
删前面只要 i - 2x <= ai <= i
最多是 n/2

*/