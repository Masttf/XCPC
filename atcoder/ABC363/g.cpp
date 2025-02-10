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
constexpr int Max = 1e18;
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
	int add = 0;
    void apply(Tag t){
    	add += t.add;
    }
};
struct Info{
	pair<int, int>mx = {-Max, 0};
	int mic = Max;
    void apply(Tag t){
    	mic += t.add;
    }
};
Info operator+ (const Info &a, const Info &b){
    Info res  = Info();
    res.mx = max(a.mx, b.mx);
	res.mic = min(a.mic, b.mic);
    return res;
}
void solve(){
    int n, q; cin >> n >> q;
    vector<int> d(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++) cin >> p[i];
   	vector<int> last(n + 1, 1);
   	vector<vector<pair<int ,int>>> op(q * 4);
   	auto insert = [&](auto self, int l, int r, int x, int y, pair<int, int>val, int p) -> void{
   		if(x <= l && r <= y){
   			op[p].push_back(val);
   			return ;
   		}
   		int mid = (l + r) >> 1;
   		if(x <= mid)self(self, l, mid, x, y, val, p << 1);
   		if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
   		return ;
   	};
    for(int i = 1; i <= q; i++){
    	int c, x, y; cin >> c >> x >> y;
    	if(last[c] < i){
    		insert(insert, 1, q, last[c], i - 1, {d[c], p[c]}, 1);
    	}
    	last[c] = i;
    	d[c] = x;
    	p[c] = y;
    }
    for(int i = 1; i <= n; i++){
    	insert(insert, 1, q, last[i], q, {d[i], p[i]}, 1);
    }
    vector<int> ans(q + 1);
    int sum = 0;
    LazySegmentTree<Info, Tag> tr(n);
    vector<multiset<int, greater<int>>> val(n + 1);
    for(int i = 1; i <= n; i++){
    	val[i].insert(-Max);
    	val[i].insert(0);
    	tr.update(i, {{0, i},  0});
    }
    vector<array<int, 3>> stk;
    auto add = [&](int x, int v, int ty) -> void{
    	if(ty)stk.push_back({-1, x, v});
    	if(v > *val[x].begin()){
    		Info temp = tr.rangeQuery(x, x);
    		temp.mx.first = v;
    		tr.update(x, temp);
    	}
    	val[x].insert(v);
    };
    auto del = [&](int x, int v, int ty) -> void{
    	if(ty)stk.push_back({-2, x, v});
    	val[x].erase(val[x].find(v));
    	if(v > *val[x].begin()){
    		Info temp = tr.rangeQuery(x, x);
    		temp.mx.first = *val[x].begin();
    		tr.update(x, temp);
    	}
    };
    auto rollback = [&](int sz) -> void{
    	while(stk.size() > sz){
    		auto [l, r, val] = stk.back();
    		stk.pop_back();
    		if(l == -1){
    			del(r, val, 0);
    			sum += val;
    		}else if(l == -2){
    			add(r, val, 0);
    			sum -= val;
    		}else{
    			tr.rangeUpdate(l, r, {-val});
    		}
    	}
    };
    auto dfs = [&](auto self, int l, int r, int p) -> void{
    	int sz = stk.size();
    	for(auto [x, y] : op[p]){
    		auto lmx = tr.rangeQuery(1, x).mx;
    		pair<int, int> rmx = {-Max, 0};
    		if(x + 1 <= n){
    			rmx.second = tr.findFirst(x + 1, n, [&](const Info &t) -> bool{
	    			return t.mic == 0;
	    		});
	    		if(rmx.second == -1)rmx.second = n + 1;
	    		if(x + 1 <= rmx.second - 1)rmx = tr.rangeQuery(x + 1, rmx.second -1).mx;
	    		else rmx = {-Max, 0};
    		}
    		if(lmx >= rmx){
    			if(lmx.first + y > 0){
    				sum += lmx.first + y;
    				add(x, -y, 1);
    				del(lmx.second, lmx.first, 1);
    				if(lmx.second < x){
    					tr.rangeUpdate(lmx.second + 1, x, {1});
    					stk.push_back({lmx.second + 1, x, 1});
    				}
    			}
    		}else{
    			if(rmx.first + y > 0){
    				sum += rmx.first + y;
    				add(x, -y, 1);
    				del(rmx.second, rmx.first, 1);
    				tr.rangeUpdate(x + 1, rmx.second, {-1});
    				stk.push_back({x + 1, rmx.second, -1});
    			}
    		}
    	}
    	if(l == r){
    		ans[l] = sum;
    		rollback(sz);
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	self(self, l, mid, p << 1);
    	self(self, mid + 1, r, p << 1 | 1);
    	rollback(sz);
    	return ;
    };
    dfs(dfs, 1, q, 1);
    for(int i = 1; i <= q; i++){
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