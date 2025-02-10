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
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    int sum = 0;
    int mx = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	sum += a[i].size();
    	mx = max(mx, (int)a[i].size());
    }
    int tot = 1;
    vector tr(26, vector<int>(sum + 5));
    auto insert = [&](string &s) -> void{
    	int p = 1;
    	int len = s.size();
    	for(auto i : s){
    		int x = i - 'a';
    		if(!tr[x][p]){
    			tr[x][p] = ++tot;
    		}
    		p = tr[x][p];
    	}
    };
    for(int i = 1; i <= n; i++){
    	insert(a[i]);
    }
    vector<int> dp(sum + 5);
    auto dfs = [&](auto self, int u) -> void{
    	for(int i = 0; i < 26; i++){
    		int v = tr[i][u];
    		if(v){
    			self(self, v);
    			dp[u] += dp[v] + 2;
    		}
    	}
    	// dbg(u, dp[u]);
    };
    dfs(dfs, 1);
    int l, r; cin >> l >> r;

    int ans = dp[1];
    ans -= mx;
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
/*
出现过
同时只有退格按键也就是删除按键
两个字母之间的距离就是最长的公共前缀
字典树？
字典树可以拿到它到其他点的最长公共前缀

注意到l，r是连续
算贡献？
如果全删除那么就是 2 * len
最长的最后一个打这样可以减掉一个最大长度

有共同的前缀的我先打？没有的

首先按公共前缀排序
以a开头 一组， aa开头一组
aa 与a这种组有前后缀关系
字典树就可以有这种公共前缀关系
同时最后一个可以少删除一次
而且一但进入子树必须要子树全搞完才能出来

定义 dpi 表示把i子树都表示的最少次数
dpi <-

分块？
可以离线

*/