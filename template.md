### MD5hash(Linux)

```
# Hashes a cpp file, ignoring whitespace and comments.
# Usage: $ sh ./hash-cpp.sh < code.cpp
cpp -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum

```

### 头文件

```c++
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
    ${1}
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
```

### AC自动机

```c++
struct AC{
	vector<vector<int>> tr;
	vector<int> fail;
	vector<int> cnt;
	vector<int> du;
	vector<int> lazy;
	int tot;
	AC(int n){
		tr = vector<vector<int>>(26, vector<int>(n + 1));
		fail.assign(n + 1, 0);
		cnt.assign(n + 1, 0);
		du.assign(n + 1, 0);
		lazy.assign(n + 1, 0);
		tot = 0;
	}
	void insert(string s){
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			if(!tr[ch][p])tr[ch][p] = ++tot;
			p = tr[ch][p];
		}
		//注意模式串是否重复
		cnt[p]++;//字符串结尾标记
	}
	//返回字符串s匹配了几次
	int get_cnt(string s){
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
		}
		return lazy[p];
	}
	void get_fail(){
		queue<int>q;
		for(int i = 0; i <26; i++){
			if(tr[i][0])q.push(tr[i][0]);
		}
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int i = 0; i < 26; i++){
				if(tr[i][now]){
					fail[tr[i][now]] = tr[i][fail[now]];//连向上一层的
					q.push(tr[i][now]);
				}else{
					tr[i][now] = tr[i][fail[now]];
				}
				
			}
		}
	}
	/*
	int query(string s){//相当于每次枚举了r然后去匹配这个后缀
		int ans = 0;
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			while(temp && cnt[temp] != -1){
			//注意是否需要重复跑,重复跑复杂度最坏nm,传递tag,拓扑建图优化
			//注意cnt为0只是说明没有以这个为后缀的字符串还需要往上跑
				ans += cnt[temp];//匹配上
				cnt[temp] = -1;//匹配过不再走
				temp = fail[temp];
			}
		}
		return ans;
	}
	*/
	void run(string s){
        get_fail();
		for(int i = 1; i <= tot; i++){
			du[fail[i]]++;
		}
		int p = 0;
		for(auto x : s){
			int ch = x - 'a';
			p = tr[ch][p];
			int temp = p;
			lazy[temp]++;
		}
		queue<int> q;
		for(int i = 1; i <= tot; i++){
			if(!du[i])q.push(i);
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			int v = fail[u];
			du[v]--;
			lazy[v] += lazy[u];
			if(!du[v])q.push(v);
		}
		return ;
	}
};
```
### PAM

```c++
struct PAM{
    static constexpr int ASIZE = 26;
    struct Node{
        int len;
        int fail;
        int cnt; //以它结尾的回文子串个数
        array<int, ASIZE> nex;
        Node() : len(0), fail(0), cnt(0), nex{} {}
    };
    vector<Node> tr;
    vector<int> res;
    int suff;
    string s;
    PAM() {
        init();
    }
    void init(){
        tr.assign(2, Node());
        tr[0].len = 0; //偶根
        tr[0].fail = 1;
        tr[1].len = -1; //奇根
        tr[1].fail = 0;
        suff = 0;
        s.clear();
        res.clear();
        /*
        你0、1一个是偶数空，一个是奇数空
        怎么跳fail都匹配不上，但是它 会在奇数根1下面挂上，表示单独的字符C。
        fail[0]=1 让0指向1，就实现了增添新的单独字符的功能。
        跳fail的本质过程是判断能不能加入新的位
        不能在单个字符周围加入新的字符形成长度为3的新回文串
        不代表不能在“0空”位置形成 aa,bb,ccaa,bb,cc这样长度为2的回文串。
        */
    }
    int newNode(){
        tr.emplace_back();
        return tr.size() - 1;
    }
    int getFail(int x){
        int pos = s.size() - 1;
        int cur = x, curlen = 0;
        while(true){
            curlen = tr[cur].len;
            if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]){
                break;
            }
            cur = tr[cur].fail;
        }
        return cur;
    }
    bool add(char c){
        s += c;
        int let = c - 'a';
        int cur = getFail(suff);
        if(tr[cur].nex[let]){
            suff = tr[cur].nex[let];
            res.push_back(suff);
            return false;
        }
        int num = newNode();
        suff = num;
        res.push_back(suff);
        tr[num].fail = tr[getFail(tr[cur].fail)].nex[let];
        tr[cur].nex[let] = num;
        tr[num].len = tr[cur].len + 2;
        tr[num].cnt = tr[tr[num].fail].cnt + 1;
        return true;
        /*
        1.如果i从0开始，i−len[x]−1可能出现负数，特判一下。
        2.求新点的fail时是getfail(fail[pos])如果写成了getfail(pos)自己会被当成是自己的最长回文后缀，fail指向自己会导致程序死循环。
        3.求新点的fail必须在建立新点之前！
        否则考虑 要建立奇数根下的点时(abbbc)，他们fail[i]=0,getfail(fail[pos])会跳到1(0匹配的话不会再1下建点)，如果1下已经建立它的点，fail也会指向他自己导致程序卡死
        */
    }
    int run(){
        vector<int> f(tr.size());
        for(auto v : res){
            f[v]++; // 在s中的出现次数
        }
        vector<vector<int>> adj(tr.size());
        for(int i = 2; i < tr.size(); i++){
            adj[tr[i].fail].push_back(i);
        }
        int ans = 0;
        auto dfs = [&](auto self, int x) -> void{
            for(auto y : adj[x]){
                self(self, y);
                f[x] += f[y];
            }
            ans = max(ans, tr[x].len * f[x]);
        };
        dfs(dfs, 0);// fail只会连到偶根
        return ans;
    }
    /*
    时间复杂度O(n),这棵树的节点个数-2就是本质不同的回文串个数
    首先建立的节点数是O(n)的
    其次因为每次执行while循环的时候cur的深度会-1
    而cur的深度总共增加了n次(for循环中)
    所以while的执行次数也是O(n)的
    */
};
```



### Manacher

```c++
struct Manacher{
	string res;
	vector<int> p;
	Manacher(string s){
		res = "^";
		for(auto x : s){
			res += '#';
			res += x;
		}
		res += "#&";
		p.resize(res.size() + 1);
		run();
		// s = abc idx 0 1 2
		// res = ^#a#b#c#& idx 2 4 6
		// s_idx -> res_idx * 2 + 2
	}
	void run(){
		int len = res.size();
		int c = 0, r = 0;
		for(int i = 1; i < len; i++){
			if(i <= r){
				p[i] = min(p[2 * c - i], r - i);
			}
			while(res[i - p[i] - 1] == res[i + p[i] + 1])p[i]++;
			if(i + p[i] > r){
				c = i;
				r = i + p[i];
			}
		}
		return ;
	}
	pair<int, int> get(){
		int start = max_element(p.begin(), p.end()) - p.begin();
		int max_len = p[start];
		return {start, max_len};
		// (i - p[i]) / 2是回文起始点,字符串下标从0开始
		// s_li = (i - p[i] + 1) / 2 - 1
		// s_ri = (i + p[i]) / 2 - 1
	}
	bool check(int l, int r){
		int len = (r - l + 1);
		int center = (l + r) / 2;
		center = center * 2 + 2;
		if(len % 2 == 0)center++;
		return p[center] >= len;
	}
};
```

### 矩阵快速幂

```c++
template <const int M, class T>
struct Matrix{
    T m[M][M];
    int row, col;
    Matrix(){
        row = 0;
        col = 0;
    }
    Matrix(int n){ //单位矩阵
        row = col = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)m[i][j] = 1;
                else m[i][j] = 0;
            }
        }
    }
    Matrix(int r, int c){
        row = r;
        col = c;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = 0;
            }
        }
    }
    Matrix(vector<vector<T>> a){
        row = a.size();
        col = a[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                m[i][j] = a[i][j];
            }
        }
    }
    Matrix operator * (const Matrix &y) const {
        Matrix res(row, y.col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < y.col; j++){
                for(int k = 0; k < col; k++){
                    res.m[i][j] += m[i][k] * y.m[k][j];
                }
            }
        }
        return res;
    }
    Matrix qmi (long long b){
        Matrix res(row);
        Matrix a = *this;
        while(b){
            if(b & 1) res = res * a;
            b >>= 1;
            a = a * a;
        }
        return res;
    }
};
using matrix = Matrix<$1>;
```

### 广义矩阵(max + )

```c++
Matrix operator * (const Matrix &y) const {
    Matrix res(row, y.col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < y.col; j++){
            for(int k = 0; k < col; k++){
                res.m[i][j] = max(res.m[i][j], m[i][k] + y.m[k][j]);
            }
        }
    }
    return res;
}
```

### 最大流

```c++
struct Max_Flow{
    //#define int long long
    static constexpr int inf = 1e18;
    struct node{
        int v, w;
    };
    int n;
    vector<node> e;
    vector<vector<int>> g;
    vector<int> h, cur;
    Max_Flow(int n){
        init(n);
    }
    void add(int u, int v, int w){
        g[u].push_back(e.size());
        e.push_back({v, w});
        g[v].push_back(e.size());
        e.push_back({u, 0});
    }
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    bool bfs (int s, int t){
        h.assign(n, -1);
        queue<int> q;
        h[s]=0;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto i : g[u]){
                auto [v, w] = e[i];
                if(h[v] == -1 && w){
                    h[v] = h[u] + 1;
                    if(v == t){
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int val){
        if(u == t)return val;
        int res = val;
        for(auto &i = cur[u]; i < (int)g[u].size(); i++){
            int j = g[u][i];
            auto [v, w] = e[j];
            if(w > 0 && h[v] == h[u] + 1){
                int d = dfs(v, t, min(res, w));
                e[j].w -= d;
                e[j ^ 1].w += d;
                res -= d;
                if(res == 0)return val;
            }
        }
        return val - res;
    }
    int flow(int s, int t){
        int ans = 0;
        while(bfs(s, t)){
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
    vector<int> mincut(){
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(h[i] != -1)res.push_back(i);
        }
        return res;
    }
    vector<int> get_mincut_edge(){
        vector<int> res;
        for(int i = 0; i < e.size(); i += 2){
            int u = e[i + 1].v;
            int v = e[i].v;
            if(h[u] != -1 && h[v] == -1){
                res.push_back(u);
            }
        }
        return res;
    }
};
```

### 最小费用最大流

```c++
struct MCFGraph {
    //#define int long long
    static constexpr int inf = 1e18;
    struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    const int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> h, dis;
    vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, inf);
        pre.assign(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            auto [d, u] = que.top();
            que.pop();
            if (dis[u] < d) continue;
            for (int i : g[u]) {
                auto[v, c, f] = e[i];
                if (c > 0 && dis[v] > d + h[u] - h[v] + f) {
                    dis[v] = d + h[u] - h[v] + f;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != inf;
    }
    MCFGraph(int n) : n(n), g(n) {}
    void addEdge(int u, int v, int c, int f) {
        g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
    }
    pair<int, int> flow(int s, int t) {
        int flow = 0;
        int cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += dis[i];
            int aug = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) aug = min(aug, e[pre[i]].c);
            for (int i = t; i != s; i = e[pre[i] ^ 1].v) {
                e[pre[i]].c -= aug;
                e[pre[i] ^ 1].c += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return {flow, cost};
    }
};
```

### 可撤销并查集

```c++
vector<int> f(n + 1), sz(n + 1);
vector<int>stk;
for(int i = 1; i <= n; i++)f[i] = i, sz[i] = 1;
auto find = [&](int x) -> int{
	while(f[x] != x){
		x = f[x];
	}
	return x;
};
auto merge = [&](int x) -> void{
	auto [a, b] = edge[x];
	int fa = find(a);
	int fb = find(b);
	if(fa == fb)return ;
	if(sz[fa] > sz[fb])swap(fa, fb);
	f[fa] = fb;
	sz[fb] += sz[fa];
	stk.push_back(fa);
};
auto rollback = [&](int x) -> void{
	while(stk.size() > x){
		int fa = stk.back();
		int fb = f[fa];
		stk.pop_back();
		f[fa] = fa;
		sz[fb] -= sz[fa];
	}
};
```

### 自动取模类

```c++
template<const int mod>
struct ModInt {
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { 
		int x0 = x + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	ModInt operator - (const ModInt &a) const {
		int x0 = x - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}
	ModInt operator * (const ModInt &a) const {
		return ModInt(1LL * x * a.x % mod);
	}
	ModInt operator / (const ModInt &a) const {
		return *this * a.inv();
	}
	bool operator == (const ModInt &a) const {
		return x == a.x;
	};
	bool operator != (const ModInt &a) const {
		return x != a.x;
	};
	void operator += (const ModInt &a) {
		x += a.x;
		if (x >= mod) x -= mod;
	}
	void operator -= (const ModInt &a) {
		x -= a.x;
		if (x < 0) x += mod;
	}
	void operator *= (const ModInt &a) {
		x = 1LL * x * a.x % mod;
	}			
	void operator /= (const ModInt &a) {
		*this = *this / a;
	}
	friend ModInt operator + (int y, const ModInt &a){
		int x0 = y + a.x;
		return ModInt(x0 < mod ? x0 : x0 - mod);
	}
	friend ModInt operator - (int y, const ModInt &a){
		int x0 = y - a.x;
		return ModInt(x0 < 0 ? x0 + mod : x0);
	}			
	friend ModInt operator * (int y, const ModInt &a){
		return ModInt(1LL * y * a.x % mod);
	}
	friend ModInt operator / (int y, const ModInt &a){
		return ModInt(y) / a;
	}
	friend ostream &operator<<(ostream &os, const ModInt &a) {
		return os << a.x;
	}
	friend istream &operator>>(istream &is, ModInt &t){
		return is >> t.x;
	}						
				
	ModInt pow(long long n) const {
	ModInt res(1), mul(x);
		while(n){
			if (n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
				
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0) u += mod;
		return u;
	}
				
};
constexpr int mod = $1;
using mint =ModInt<mod>;template<const int T>
struct ModInt {
	const static int mod = T;
	int x;
	ModInt(int x = 0) : x(x % mod) {}
	ModInt(long long x) : x(int(x % mod)) {} 
	int val() { return x; }
	ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
	ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
	ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
	ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
	bool operator == (const ModInt &a) const { return x == a.x; };
	bool operator != (const ModInt &a) const { return x != a.x; };
	void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
	void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
	void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }			
	void operator /= (const ModInt &a) { *this = *this / a; }
	friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
	friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }			
	friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
	friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
	friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
	friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}						
				
	ModInt pow(long long n) const {
	ModInt res(1), mul(x);
		while(n){
			if (n & 1) res *= mul;
			mul *= mul;
			n >>= 1;
		}
		return res;
	}
				
	ModInt inv() const {
		int a = x, b = mod, u = 1, v = 0;
		while (b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0) u += mod;
		return u;
	}
				
};
constexpr int mod = $1;
using mint =ModInt<mod>;
```

### lca

```c++
vector<int> dep(n + 1);
vector<vector<int>> f(25, vector<int>(n + 1));
auto dfs = [&](auto self, int now, int father) -> void{
	dep[now] = dep[father]+1;
	f[0][now] = father;
	for(int i = 1; i <= 20; i++){
		f[i][now] = f[i - 1][f[i - 1][now]];
	}
	for(auto v : g[now]){
		if(v == father)continue;
		self(self, v, now);
	}
	return ;
};
dfs(dfs, 1, 0);

auto lca = [&](int a, int b) -> int{
	if(dep[a] < dep[b])swap(a,b);
	for(int i = 20; i >= 0; i--){
		if(dep[a] - (1ll << i) >= dep[b])a = f[i][a];
	}
	if(a == b)return a;
	for(int i = 20; i >= 0; i--){
		if(f[i][a] != f[i][b]){
			a = f[i][a];
			b = f[i][b];
		}
	}
	return f[0][a];
};
```

### dfn序求lca O(1)

```c++
vector<int>dfn(n + 1), dep(n + 1);
vector st(21, vector<pair<int, int>>(n + 1));
int tot = 0;
auto dfs = [&](auto self, int now, int father) -> void{
    dfn[now] = ++tot;
    dep[now] = dep[father] + 1;
    st[0][tot] = {dep[now], father};
    for(auto v : g[now]){
        if(v == father)continue;
        self(self, v, now);
    }
};
dfs(dfs, 1, 0);
for(int k = 1; k <= 20; k++){
    for(int i = 1; i + (1ll << k) <= n + 1; i++){
        st[k][i] = min(st[k - 1][i], st[k - 1][i + (1ll << (k - 1))]);
    }
}
auto lca = [&](int a, int b) -> int{
    if(a == b)return a;
    if(dfn[a] > dfn[b])swap(a, b);
    int l = dfn[a] + 1;
    int r = dfn[b];
    int len = (r - l + 1);
    int d = __lg(len);
    return min(st[d][l], st[d][r - (1ll << d) + 1]).second;
};
```

### cdq分治

```c++
auto cdq = [&](auto self, int l, int r) -> void{
	if(l == r)return ;
	int mid = (l + r) >> 1;
	self(self, l, mid);
	self(self, mid + 1, r);
	int i = l, j = mid + 1;
	for(; j <= r; j++){
		while(i <= mid && q[j].b > q[i].b){
			add(q[i].c, 1);
			i++;
		}
		du[q[j].a] += ask(q[j].c - 1);
	}
	for(i--; i >= l; i--){
		add(q[i].c, -1);
	}
	sort(q.begin() + l, q.begin() + r + 1, cmp);//第二关键字排序
};
cdq(cdq, 1, n);
```

### 整体二分

```
struct Num {
  int x, y, val;
};
struct node{
	int x1, y1, x2, y2, k, id;
};
void solve(){
    int n, q; cin >> n >> q;
    vector a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
	vector tr(n + 1, vector<int>(n + 1));
	auto add = [&](int x, int y, int d)->void{
	    for (int i = x; i <= n; i += lowbit(i)) {
	        for (int j = y; j <= n; j += lowbit(j)) {
	            tr[i][j] += d;
	        }
	    }
	};
	auto ask = [&](int x, int y)->int{
	    int res = 0;
	    for (int i = x; i > 0; i -= lowbit(i)) {
	        for (int j = y; j > 0; j -=lowbit(j)) {
	            res += tr[i][j];
	        }
	    }
   		return res;
	};
	vector<node>Q;
	vector<int>ans(q + 1);
	for(int i = 1;i <= q; i++){
		int x1, y1, x2, y2, k;cin >> x1 >> y1 >> x2 >> y2 >>k;
		Q.push_back({x1, y1, x2, y2, k, i});
	}
	vector<Num>temp;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			temp.push_back({i, j, a[i][j]});
		}
	}
	auto fz = [&](auto self,int l,int r,vector<Num>b,vector<node>QQ)->void{
		if(l == r){
			for(auto [x1, y1, x2, y2, k, id] : QQ){
				//dbg(id);
				ans[id] = l;
			}
			return ;
		}
		if(QQ.empty())return ;
		int mid = (l + r) >> 1;
		vector<Num> a1, a2;
  		vector<node> q1, q2;
  		for(auto [x, y, val] : b){
  			if(val <= mid){
  				a1.push_back({x, y, val});
  				add(x, y, 1);
  			}else a2.push_back({x, y, val});
  		}
  		for(auto [x1, y1, x2, y2, k, id] : QQ){
  			int d=ask(x2, y2) + ask(x1 - 1, y1 - 1) - ask(x1 - 1,y2) - ask(x2, y1 - 1);
  			if(k <= d){
  				q1.push_back({x1, y1, x2, y2, k, id});
  			}else{
  				q2.push_back({x1, y1, x2, y2, k - d, id});
  			}
  		}
  		for(auto [x,y,val]:b){
  			if(val<=mid){
  				add(x,y,-1);
  			}
  		}
  		self(self,l,mid,a1,q1);
  		self(self,mid+1,r,a2,q2);
	};
	fz(fz,0,1e9,temp,Q);
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    return ;
}
```

### 数位dp

```c++
auto get = [&](int x)->int{
    vector dp(10,vector(10,vector(2,vector<int>(2))));
    vector<int>p;
    int temp=x;
    while(temp){
        p.push_back(temp%10);
        temp/=10;
    }
    auto dfs = [&](auto self,int now,int last,int limit,int lead)->int{
        if(now==-1)return 1;
        if(dp[now][last][limit][lead]!=0)return dp[now][last][limit][lead];
        int res=0;
        for(int i=0;i<=(limit?p[now]:9);i++){
            if(lead==1)res+=self(self,now-1,i,limit&&i==p[now],i==0);
            else{
                if(abs(i-last)>=2)res+=self(self,now-1,i,limit&&i==p[now],0);
            }
        }
        return dp[now][last][limit][lead]=res;
    };
    return dfs(dfs,p.size()-1,0,1,1);
};
```

### 01trie

```c++
struct trie{
	struct node{
		int l, r;
	};
	int tot;
	vector<node>tr;
	vector<array<int, 2>> tag;
	int Max = (1ll << 31) - 1;
	trie(int n){
		tot = 1;
		tr.assign(n, {0, 0});
		tag.assign(n, {0, 0});
	}
	void cg(int p, array<int, 2> val){
		tag[p][0] |= val[0];
		tag[p][1] -= tag[p][1] & val[0];
		tag[p][1] ^= val[1]; 
	}
	void down(int p, int dep){
		if((tag[p][0] >> dep) & 1){
			merge(tr[p].r, tr[p].l, dep - 1);
		}
		if((tag[p][1] >> dep) & 1){
			swap(tr[p].l, tr[p].r);
		}
		if(tr[p].l)cg(tr[p].l, tag[p]);
		if(tr[p].r)cg(tr[p].r, tag[p]);
		tag[p] = {0, 0};
	}
	void merge(int &x, int &y, int dep){ // x <- y
		if(!y || !x){
			x = x | y;
			y = 0;
			return ;
		}
		if(dep == -1){
			y = 0;
			return ;
		}
		down(x, dep);down(y, dep);
		merge(tr[x].l, tr[y].l, dep - 1);
		merge(tr[x].r, tr[y].r, dep - 1);
		y = 0;
		return ;
	}
	void insert(int x){
		int p = 1;
		for(int i = 30; i >= 0; i--){
			int d = (x >> i) & 1;
			down(p, i);
			if(d == 0){
				if(!tr[p].l)tr[p].l = ++tot;
				p = tr[p].l;
			}else{
				if(!tr[p].r)tr[p].r = ++tot;
				p = tr[p].r;
			}
		}
	}
	int query(int x){
		int res = 0;
		int p = 1;
		for(int i = 30; i >= 0; i--){
			down(p, i);
			int d = (x >> i) & 1;
			d = 1 ^ d;
			if(d == 0){
				if(tr[p].l){
					res += 1ll << i;
					p = tr[p].l;
				}else{
					p = tr[p].r;
				}
			}else{
				if(tr[p].r){
					res += 1ll << i;
					p = tr[p].r;
				}else{
					p = tr[p].l;
				}
			}
			
		}
		return res;
	}
};
```

### 线段树合并

- 注意合并的时候考虑贡献要是未覆盖
- 只要需要考虑根节点的合并即可

```c++
auto merge = [&](auto self, int l, int r, int x, int y) -> int{
    if(!x || !y)return x | y;
    int mid = (l + r) >> 1;
    int rt = ++tot;
    if(l == r){
        tr[rt].val = l;
        tr[rt].cnt = tr[x].cnt + tr[y].cnt;
        return rt;
    }
    tr[rt].l = self(self, l, mid, tr[x].l, tr[y].l);
    tr[rt].r = self(self, mid + 1, r, tr[x].r, tr[y].r);
    up(rt);
    return rt;
};
auto dfs2 = [&](auto self, int now, int father) -> void{
    for(auto v : g[now]){
        if(v == father)continue;
        self(self, v, now);
        root[now] = merge(merge, 1, 1e5, root[v], root[now]);
    }
};
//引用版
auto merge = [&](auto self, int l, int r, int &x, int y) -> void{
    if(!x || !y){
        x = x | y;
        return ;
    }
    if(l == r){
        tr[x].val += tr[y].val;
        return ;
    }
    int mid = (l + r) >> 1;
    tr[x].val += tr[y].val;
    self(self, l, mid, tr[x].l, tr[y].l);
    self(self, mid + 1, r, tr[x].r, tr[y].r);
};
//拿到父亲那边的子树情况
auto run = [&](auto self, int l, int r, int x, int y) -> void{
    if(tr[x].cnt - tr[y].cnt == 0)return ;
    if(tr[y].cnt == 0)return ;
    int mid = (l + r) >> 1;
    if(l == r){
        int d = tr[x].cnt - tr[y].cnt;
        return ;
    }
    self(self, l, mid, tr[x].l, tr[y].l, f);
    self(self, mid + 1, r, tr[x].r, tr[y].r, f);
    return ;
};
auto dfs2 = [&](auto self, int now, int father) -> void{
    for(auto v : g[now]){
            if(v == father)continue;
            run(run, 1, n, root[1], root[v]);
            self(self, v, now);
    }
};
```

### 线段树合并示例（维护链信息）

```c++
constexpr long long Max = 1e18;
struct node{
	int l, r;
	long long val, tag;
};
void solve(){
	int n; cin >> n;
	vector<int> c(n + 1), w(n + 1);
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	vector<vector<int>>g(n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> root(n + 1);
	vector<long long> dp(n + 1);
	vector<node> tr(n * 40);
	int tot = 0;
	long long sum = 0;
	auto cg = [&](int p, long long val) -> void{
		tr[p].val += val;
		tr[p].tag += val;
	};
	auto down = [&](int p) -> void{
		if(tr[p].tag != 0){
			int ls = tr[p].l;
			int rs = tr[p].r;
			if(ls)cg(ls, tr[p].tag);
			if(rs)cg(rs, tr[p].tag);
			tr[p].tag = 0;
		}
	};
	auto updata = [&](auto self, int l, int r, int x, int val, int &p) -> void{
		if(!p)p = ++tot;
		tr[p].val = val;
		if(l == r)return ;
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, val, tr[p].l);
		else self(self, mid + 1, r, x, val, tr[p].r);
	};
	auto merge = [&](auto self, int l, int r, int &x, int y, long long &res) -> void{
		if(!x || !y){
			x = x | y;
			return ;
		}
		if(l == r){
			res = max(res, tr[x].val + tr[y].val + sum);
			tr[x].val = max(tr[x].val, tr[y].val);
			return ;
		}
		down(x);down(y);
		tr[x].val = max(tr[x].val, tr[y].val);
		int mid = (l + r) >> 1;
		self(self, l, mid, tr[x].l, tr[y].l, res);
		self(self, mid + 1, r, tr[x].r, tr[y].r, res);
		return ;
	};
	auto dfs2 = [&](auto self, int now, int father) -> void{
		sum = 0;
		long long sm = 0;
		for(auto v : g[now]){
			if(v == father)continue;
			self(self, v, now);
			sm += dp[v];
		}
		sum = sm;
		dp[now] = sum;
		updata(updata, 1, n, c[now], w[now], root[now]);
		for(auto v : g[now]){
			if(v == father)continue;
			cg(root[v], -dp[v]);
			merge(merge, 1, n, root[now], root[v], dp[now]);
		}
		cg(root[now], sm);//先减后加刚刚好是向上延申一个节点的价值

	};
	dfs2(dfs2, 1, 0);
	cout << dp[1] << '\n';
	return ;
}
```



### 线段树优化建图

```c++
void solve(){
	int n,m,p;cin>>n>>m>>p;
	vector<int>ps(n+1);
	vector g(8*n+2*m+1,vector<pair<int,int>>());
	int pdx=4*n;// > pdx 是出树 
    //可以根据连点是否都是区间来判断要建几个树
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(p!=1)g[p + pdx].push_back({p / 2 + pdx,0});
		if(l == r){
			ps[l] = p;
			g[p+pdx].push_back({p,0});
			g[p].push_back({p+pdx,0});
			return ;
		}
		int mid=(l+r)>>1;
		g[p].push_back({p<<1,0});
		g[p].push_back({p<<1|1,0});
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};
	bulid(bulid,1,n,1);

	auto link = [&](auto self,int l,int r,int x,int y,int k,int t,int p)->void{
		if(x<=l&&r<=y){
			if(t==1){
				g[k].push_back({p,1});
				g[p+pdx].push_back({k+1,1});// 出边从出树连出
			}else{
				g[k+1].push_back({p,1});
				g[p+pdx].push_back({k,1});
			}
			
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,k,t,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,k,t,p<<1|1);
	};
	for(int i=1;i<=m;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;
        // a,b 连向 c, d 双向
		link(link,1,n,a,b,2*i-1+2*pdx,1,1);
		link(link,1,n,c,d,2*i-1+2*pdx,2,1);
	}
	vector<int>d(8*n+2*m+1,INT_MAX);
	auto dijkstra = [&]()->void{
		vector<int>vis(8*n+2*m+1);
		p=ps[p]+pdx;
		d[p]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		q.push({0,p});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto [v,w]:g[u]){
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					q.push({d[v],v});
				}
			}
		}
	};
	dijkstra();
	for(int i=1;i<=n;i++){
		cout<<d[ps[i]+pdx]/2<<'\n';
	}
	return ;
}
```

### 线段树分治

```c++
constexpr int maxn = 2e5 + 5;
void solve(){
	int n, m; cin >> n >> m;
	vector<int> l(n + 1), r(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}
	vector<pair<int, int>>edge;
	vector<int> f(n + 1), sz(n + 1), ans(n + 1);
	vector<int>stk;
	for(int i = 1; i <= n; i++)f[i] = i, sz[i] = 1;
	auto find = [&](int x) -> int{
		while(f[x] != x){
			x = f[x];
		}
		return x;
	};
	auto merge = [&](int x) -> void{
		auto [a, b] = edge[x];
		int fa = find(a);
		int fb = find(b);
		if(fa == fb)return ;
		if(sz[fa] > sz[fb])swap(fa, fb);
		f[fa] = fb;
		sz[fb] += sz[fa];
		ans[fa] -= ans[fb];
		stk.push_back(fa);
	};
	auto rollback = [&](int x) -> void{
		while(stk.size() > x){
			int fa = stk.back();
			int fb = f[fa];
			stk.pop_back();
			f[fa] = fa;
			sz[fb] -= sz[fa];
			ans[fa] += ans[fb];
		}
	};
	vector<vector<int>> tr(maxn * 4);
	auto updata = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
		if(x <= l && r <= y){
			tr[p].push_back(val);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
	};
	auto dfs = [&](auto self, int l, int r, int p) -> void{
		int sz = stk.size();
		for(auto x : tr[p])merge(x);
		if(l == r){
			ans[find(1)]++;
			rollback(sz);
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, l, mid, p << 1);
		self(self, mid + 1, r, p << 1 | 1);
		rollback(sz);
	};
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		int ll = max(l[u], l[v]);
		int rr = min(r[u], r[v]);
		if(ll <= rr){
			updata(updata, 1, maxn, ll, rr, edge.size(), 1);
			edge.push_back({u, v});
		}
	}
	dfs(dfs, 1, maxn, 1);
	for(int i = 1; i <= n; i++){
		if(ans[i])cout << i << ' ';
	}
	cout << '\n';
	return ;
}
```

### 可持久化01字典树区间异或第k大

```c++
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	vector t(2,vector<int>((n+1)*35));
	vector<int>val((n+1)*35);
	int tot=0;
	auto ins = [&](int u,int v,int x)->void{
		for(int i=31;i>=0;i--){
			t[0][u]=t[0][v];
			t[1][u]=t[1][v];
			int d=x>>i&1;
			t[d][u]=++tot;
			u=t[d][u];
			v=t[d][v];
			val[u]=val[v]+1;
		}
	};

	auto ask = [&](int u,int x,int k)->int{
		int res=0;
		for(int i=31;i>=0;i--){
			int d=x>>i&1;
			d^=1;
			int sz=val[t[d][u]];
			if(sz>=k){
				res+=1ll<<i;
			}else{
				k-=sz;
				d^=1;
			}
			u=t[d][u];
		}
		return res;
	};

	vector<int>root(n+1);
	root[0]=++tot;
	ins(root[0],0,0);
	priority_queue<node>q;
	int ans=0;
	for(int i=1;i<=n;i++){
		root[i]=++tot;
		ins(root[i],root[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		q.push({ask(root[i],a[i],1),i,1});
	}
	for(int i=1;i<=m;i++){
		int res=q.top().val;
		int id=q.top().id;
		int rk=q.top().rk;
		q.pop();
		ans+=res;
		if(rk==n)continue;
		q.push({ask(root[id],a[id],rk+1),id,rk+1});
	}
	cout<<ans<<'\n';
	return ;
}
```

### 可持久化线段树 区间第k小

```c++
struct node{
	int l,r,sum;
};
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++)cin>>a[i],p.push_back(a[i]);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};

	vector<node>tr(n<<5);
	vector<int>root(n+1);
	int tot=0;
	
	auto bulid = [&](auto self,int &u,int l,int r)->void{
		u=++tot;
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,tr[u].l,l,mid);
		self(self,tr[u].r,mid+1,r);
		return ;
	};

	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].sum++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};

	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		if(l==r)return l;
		int mid=(l+r)>>1;
		int d=tr[tr[u].l].sum-tr[tr[v].l].sum;
		if(d>=k)return self(self,tr[u].l,tr[v].l,l,mid,k);
		else return self(self,tr[u].r,tr[v].r,mid+1,r,k-d);
	};

	bulid(bulid,root[0],1,n);
	for(int i=1;i<=n;i++){
		int d=get(a[i]);
		updata(updata,root[i],root[i-1],1,n,d);
	}
	for(int i=1;i<=m;i++){
		int l,r,k;cin>>l>>r>>k;
		int d=query(query,root[r],root[l-1],1,n,k);
		cout<<p[d-1]<<'\n';
	}
	return ;
}
```

### 懒标记线段树

```c++
template<class Info, class Tag>
struct LazySegmentTree{
	int n;
	vector<Info> info;
	vector<Tag> tag;
	LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()){
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(vector<T> init_){ //注意下标从1开始也就是[0] 是空
        init(init_);
    }
    void init(int n_, Info v_ = Info()){
        init(vector(n_ + 1, v_));
    }
    template<class T>
    void init(vector<T> init_){
        n = init_.size() - 1;
        info.assign(n * 4, Info());
        tag.assign(n * 4, Tag());
        auto bulid = [&](auto self, int l, int r, int p) -> void{
            if(l == r){
                info[p] = init_[l];
                return ;
            }
            int mid = (l + r) >> 1;
            self(self, l, mid, p << 1);
            self(self, mid + 1, r, p << 1 | 1);
            up(p);
        };
        bulid(bulid, 1, n, 1);
    }
    void cg(int p, const Tag &v){
    	info[p].apply(v);
    	tag[p].apply(v);
    }
    void up (int p){
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void down (int p){
    	cg(p << 1, tag[p]);
    	cg(p << 1 | 1, tag[p]);
    	tag[p] = Tag();
    }
    void update(int l, int r, int x, const Info &v, int p){
        if(l == r){
            info[p] = v;
            return ;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid)update(l, mid, x, v, p << 1);
        else update(mid + 1, r, x, v, p << 1 | 1);
        up(p);
    }
    void update(int x, const Info &v){
        update(1, n, x, v, 1);
    }
    Info rangeQuery(int l, int r, int x, int y, int p){
        if(x <= l && r <= y)return info[p];
        Info res = Info();
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid)res = res + rangeQuery(l, mid, x, y, p << 1);
        if(y > mid)res = res + rangeQuery(mid + 1, r, x, y, p << 1 | 1);
        return res;
    }
    Info rangeQuery(int l, int r){
        return rangeQuery(1, n, l, r, 1);
    }
    void rangeUpdate(int l, int r, int x, int y, const Tag &val, int p){
    	if(x <= l && r <= y){
    		cg(p, val);
    		return ;
    	}
    	down(p);
    	int mid = (l + r) >> 1;
    	if(x <= mid)rangeUpdate(l, mid, x, y, val, p << 1);
    	if(y > mid)rangeUpdate(mid + 1, r, x, y, val, p << 1 | 1);
    	up(p);
    }
    void rangeUpdate(int l, int r, const Tag &val){
    	rangeUpdate(1, n, l, r, val, 1);
    }
    template<class F>
    int findFirst(int l, int r, int x, int y, int p, F &&check){
        if(x <= l && r <= y){
            if(!check(info[p]))return -1;
            if(l == r)return l;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(x <= mid){
            int res = findFirst(l, mid, x, y, p << 1, check);
            if(res != -1)return res;
        }
        if(y > mid)return findFirst(mid + 1, r, x, y, p << 1 | 1, check);
        return -1;
    }
    template<class F>
    int findFirst(int l, int r, F &&check){
        return findFirst(1, n, l, r, 1, check);
    }
    template<class F>
    int findLast(int l, int r, int x, int y, int p, F &&check){
        if(x <= l && r <= y){
            if(!check(info[p]))return -1;
            if(l == r)return l;
        }
        down(p);
        int mid = (l + r) >> 1;
        if(y > mid){
            int res = findLast(mid + 1, r, x, y, p << 1 | 1, check);
            if(res != -1)return res;
        }
        if(x <= mid)return findLast(l, mid, x, y, p << 1, check);
        return -1;
    }
    template<class F>
    int findLast(int l, int r, F &&check){
        return findLast(1, n, l, r, 1, check);
    }
};
struct Tag{

	void apply(Tag t){

	}
};
struct Info{

	void apply(Tag t){

	}
};
Info operator+ (const Info &a, const Info &b){
	Info res  = Info();

	return res;
}
```

### 线段树

```c++
template<class Info>
struct SegmentTree{
	int n;
	vector<Info> info;
	SegmentTree() : n(0) {}
	SegmentTree(int n_, Info v_ = Info()){
		init(n_, v_);
	}
	template<class T>
	SegmentTree(vector<T> init_){ //注意下标从1开始也就是[0] 是空
		init(init_);
	}
	void init(int n_, Info v_ = Info()){
		init(vector(n_ + 1, v_));
	}
	template<class T>
	void init(vector<T> init_){
		n = init_.size() - 1;
		info.assign(n * 4, Info());
		auto bulid = [&](auto self, int l, int r, int p) -> void{
			if(l == r){
				info[p] = init_[l];
				return ;
			}
			int mid = (l + r) >> 1;
			self(self, l, mid, p << 1);
			self(self, mid + 1, r, p << 1 | 1);
			up(p);
		};
		bulid(bulid, 1, n, 1);
	}
	void up (int p){
		info[p] = info[p << 1] + info[p << 1 | 1];
	}
	void update(int l, int r, int x, const Info &v, int p){
		if(l == r){
			info[p] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid)update(l, mid, x, v, p << 1);
		else update(mid + 1, r, x, v, p << 1 | 1);
		up(p);
	}
	void update(int x, const Info &v){
		update(1, n, x, v, 1);
	}
	Info rangeQuery(int l, int r, int x, int y, int p){
		if(x <= l && r <= y)return info[p];
		Info res = Info();
		int mid = (l + r) >> 1;
		if(x <= mid)res = res + rangeQuery(l, mid, x, y, p << 1);
		if(y > mid)res = res + rangeQuery(mid + 1, r, x, y, p << 1 | 1);
		return res;
	}
	Info rangeQuery(int l, int r){
		return rangeQuery(1, n, l, r, 1);
	}
	template<class F>
	int findFirst(int l, int r, int x, int y, int p, F &&check){
		if(x <= l && r <= y){
			if(!check(info[p]))return -1;
			if(l == r)return l;
		}
		int mid = (l + r) >> 1;
		if(x <= mid){
			int res = findFirst(l, mid, x, y, p << 1, check);
			if(res != -1)return res;
		}
		if(y > mid)return findFirst(mid + 1, r, x, y, p << 1 | 1, check);
		return -1;
	}
	template<class F>
	int findFirst(int l, int r, F &&check){
		return findFirst(1, n, l, r, 1, check);
	}
	template<class F>
	int findLast(int l, int r, int x, int y, int p, F &&check){
		if(x <= l && r <= y){
			if(!check(info[p]))return -1;
			if(l == r)return l;
		}
		int mid = (l + r) >> 1;
		if(y > mid){
			int res = findLast(mid + 1, r, x, y, p << 1 | 1, check);
			if(res != -1)return res;
		}
		if(x <= mid)return findLast(l, mid, x, y, p << 1, check);
		return -1;
	}
	template<class F>
	int findLast(int l, int r, F &&check){
		return findLast(1, n, l, r, 1, check);
	}
};
struct Info{
	
};
Info operator+(const Info &a, const Info &b){
	Info res = Info();

	return res;
}
```

### 莫队 

- 注意保证区间非负

```c++
int block = sqrt(n);
while(block * block < n)block++;
while(block * block > n)block--;
sort(Q.begin() + 1, Q.end(), [&](node a, node b) -> bool{
	if(a.l / block != b.l / block){
		return a.l < b.l;
	}
	if((a.l / block) & 1)return a.r > b.r;
	return a.r < b. r;
});
auto add = [&](int x) -> void{
	
};
auto del = [&](int x) -> void{
	
};
int L = 1, R = 0;
for(int i = 1; i <= q; i++){
	auto [l, r, id] = Q[i];
    while(L > l)add(--L);
    while(R < r)add(++R);
    while(L < l)del(L++);
    while(R > r)del(R--);
	ans[id] = mx;
}
```

### 回滚莫队

- O(1) add/del

```c++
vector<int> ans(q + 1);
vector<node> Q;
int mx = 0;
int block = sqrt(n);
vector<array<int, 4>> stk;
auto add = [&](int x, int tp) -> void{
	if(tp)stk.push_back();
	
};
auto rollback = [&]() -> void{
	while(stk.size()){
		
	}
};
for(int i = 1; i <= q; i++){
	int l, r; cin >> l >> r;
	if(l / block == r / block){
		for(int j = l; j <= r; j++){
			add(j, 1);
		}
		ans[i] = mx;
		rollback();
	}else Q.push_back({l, r, i, l / block});
}
sort(Q.begin(), Q.end(), [&](node x, node y) -> bool{
	if(x.blk != y.blk)return x.l < y.l;
	return x.r < y.r;
});
int sz = Q.size();
for(int i = 0, l, r; i < sz; i++){
	auto [ll, rr, id, blk] = Q[i];
	if(!i || blk != Q[i - 1].blk){
		l = min(n + 1, blk * block + block);
		r = l - 1;
		mx = 0;
		cnt.assign(n + 1, 0);
	}
	while(r < rr)add(++r, 0);
	while(l > ll)add(--l, 1);
	ans[id] = mx;
	rollback();
	l = min(n + 1, blk * block + block);
}
```

### bitset(遍历1的位置)

```c++
for(int j = r1._Find_first(); j <= n; j = r1._Find_next(j))
```

### 斯坦纳树(O($3^kn + 2^knlogm$))

```c++
constexpr int Max = 1e18;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    vector<int>limit(k + 1);
    for(int i = 1; i <= k; i++) cin >> limit[i];
    vector dp(n + 1, vector<int>((1 << k), Max));
	for(int i = 1; i <= k; i++){
		dp[limit[i]][1 << (i - 1)] = 0;
	}
	auto dijkstra = [&](int s) -> void{
		priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>>q;
		for(int i = 1; i <= n; i++){
			if(dp[i][s] != Max){
				q.push({dp[i][s], i});
			}
		}
		while(!q.empty()){
			auto [val, u] = q.top();
			q.pop();
			if(val > dp[u][s])continue;
			for(auto [v, w] : g[u]){
				if(dp[v][s] > dp[u][s] + w){
					dp[v][s] = dp[u][s] + w;
					q.push({dp[v][s], v});
				}
			}
		}
	};
	for(int i = 1; i < (1 << k); i++){
		for(int s = i; s != 0; s = i & (s - 1)){
			for(int j = 1; j <= n; j++){
				dp[j][i] = min(dp[j][i], dp[j][s] + dp[j][i ^ s]);
			}
		}
		dijkstra(i);
	}
	cout << dp[limit[1]][(1 << k) - 1] << '\n';
    return ;
}
```

### 模拟最小费用流

- 二分图有一边点数很少
- $nk^3 + nk^2 log n$

```c++
struct TwoMCFGraph{
    //#define int long long
    static constexpr int inf = 1e18;
    int n, k;
    vector<vector<int>> cost;
    vector<int>bl, lim;
    vector<vector<set<pair<int, int>>>>q;
    TwoMCFGraph(){}
    TwoMCFGraph(int n_, int k_){
        n = n_;
        k = k_;
        cost.assign(n + 1, vector<int>(k + 1, inf));
        for(int i = 1; i <= n; i++)cost[i][0] = 0;
        bl.assign(n + 1, -1);
        lim.assign(k + 1, 0);
        q.assign(k + 1, vector(k + 1, set<pair<int, int>>()));
    }
    void add (int x, int c){
        for(int i = 1; i <= k; i++){
            if(i == c)continue;
            q[c][i].insert({cost[x][i] - cost[x][c], x});
        }
        bl[x] = c;
    };
    void del (int x){
        for(int i = 1; i <= k; i++){
            if(i == bl[x])continue;
            q[bl[x]][i].erase({cost[x][i] - cost[x][bl[x]], x});
        }
        bl[x] = -1;
    };
    int flow(){
        int res = 0;
        int tot = n;
        for(int i = 1; i <= n; i++)add(i, 0);
        while(tot--){
            vector g(k + 1, vector<int>(k + 1));
            for(int i = 0; i <= k; i++){
                for(int j = 1; j <= k; j++){
                    if(q[i][j].empty())g[i][j] = inf;
                    else g[i][j] = q[i][j].begin() -> first;
                }
            }
            vector<int> dis(k + 1,), pre(k + 1, -1);
            vector<int> vis(k + 1, 0);
            queue<int> que;
            dis[0] = 0;
            que.push(0);
            while(!que.empty()){
                int u = que.front();
                que.pop();
                vis[u] = 0;
                for(int i = 1; i <= k; i++){
                    if(dis[u] + g[u][i] < dis[i]){
                        dis[i] = dis[u] + g[u][i];
                        pre[i] = u;
                        if(!vis[i]){
                            vis[i] = 1;
                            que.push(i);
                        }
                    }
                }
            }
            int now = -1;
            for(int i = 1; i <= k; i++){
                if(lim[i] && (now == -1 || dis[i] < dis[now])){
                    now = i;
                }
            }
            if(now == -1)break; // 注意这是满流条件
            // if(now == -1 || dis[now] > 0)break; // 这是任意流条件
            res += dis[now];
            lim[now]--;
            while(now){
                int fa = pre[now];
                assert(fa != -1);
                int v = q[fa][now].begin() -> second;
                del(v);
                add(v, now);
                now = fa;
            }
        }
        return res;
    }
};
void solve(){
    int n, k; cin >> n >> k;
    TwoMCFGraph g(n, k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cin >> g.cost[i][j];
        }
    }
    for(int i = 1; i <= k; i++) cin >> g.lim[i];
    cout << g.flow() << '\n';
    return ;
}
```

### tarjan

```c++
vector<int> dfn(n + 1), low(n + 1);
vector<vector<int>> g(n + 1);
vector<int> bl(n + 1);
int idx = 0, cnt = 0;
stack<int>s;
auto tarjan = [&](auto self, int u) -> void{
    dfn[u] = low[u] = ++idx;
    s.push(u);
    for(auto v : g[u]){
        if(!dfn[v]){//还没有访问过
            self(self, v);
            low[u] = min(low[u], low[v]);
        }else if(!bl[v]){//该连通块存在
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){//是连通块的根节点
        cnt++;
        int y;
        do{
            y = s.top();
            s.pop();
            bl[y] = cnt;
        }while(y != u);
    }
    return ;
};
```

### ST表

```c++
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
```

