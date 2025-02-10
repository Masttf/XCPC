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
template<class Info>
struct Fenwick{
	#define lowbit(x) ((x) & (-x))
	vector<Info> tr;
	int n;
	Fenwick(int n_) : n(n_), tr(n_ + 1){}
	void add(int x, Info val){
		while(x <= n){
			tr[x] = tr[x] + val;
			x += lowbit(x);
		}
	}
	Info ask(int x){
		Info res = Info();
		while(x > 0){
			res = res + tr[x];
			x -= lowbit(x);
		}
		return res;
	}
	Info rangeAsk(int l, int r){
		return ask(r) - ask(l - 1);
	}
	template<class F>
	int find(F &&check){
		int p = 0;
		Info res = Info();
		int d = __lg(n);
		for(int i = d; i >= 0; i--){
			int v = p + (1ll << i);
			if(v <= n && check(res + tr[v])){
				p = v;
				res = res + tr[p];
			}
		}
		return p;
	}
};

void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    int sum = 0;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	sum += a[i].size();
    	b[i] = a[i].size();
    }
    vector st(21, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	st[0][i] = b[i];
    }
    for(int k = 1; k <= 20; k++){
    	for(int i = 1; i + (1 << k) <= n + 1; i++){
    		st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    	}
    }
    auto get = [&](int l, int r) -> int{
    	int d = __lg(r - l + 1);
    	return max(st[d][l], st[d][r - (1 << d) + 1]);
    };
    vector<int> ans(m + 1);
    vector Q(n + 1, vector<pair<int, int>>());
    for(int i = 1; i <= m; i++){
    	int l, r; cin >> l >> r;
    	Q[r].push_back({l, i});
    }
    int tot = 1;
    vector tr(26, vector<int>(sum + 5));
    vector<int> last(sum + 5);
    Fenwick<int> seg(n + 1);
    auto insert = [&](string &s, int pos) -> void{
    	int p = 1;
    	for(auto i : s){
    		int x = i - 'a';
    		if(!tr[x][p]){
    			tr[x][p] = ++tot;
    		}
    		p = tr[x][p];
    		if(last[p]){
    			seg.add(last[p], -2);
    		}
    		last[p] = pos;
    		seg.add(last[p], 2);
    	}
    };
    for(int i = 1; i <= n; i++){
    	insert(a[i], i);
    	for(auto [l, id] : Q[i]){
    		ans[id] = seg.rangeAsk(l, i);
    		ans[id] -= get(l, i);
    	}
    }
    for(int i = 1; i <= m; i++){
    	cout << ans[i] << '\n';
    }
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

可以离线

区间查询能不能变成前后缀？
c的做法是dfs一遍树，在这里肯定不行了
dfs 一遍有的节点 时间复杂度是O长度
怎么做到log？

log???
a aa
2 还是 2
1 - 2
2 - 2

区间查询有什么性质？
可以离线，离线有啥用？ 不具备区间可减性
哦不对维护最远出现即可
hh的项链，dfs只管有没有

只计算 >= l 的节点有可能嘛？
还需要一个什么东西维护贡献
每次插入新的只会影响一次
每个节点维护一个时间的贡献的序列？
不可行
对每个节点单独算贡献可行

*/