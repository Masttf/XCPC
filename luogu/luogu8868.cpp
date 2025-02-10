#include<bits/stdc++.h>
//#define int long long
#define ull unsigned long long
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
	array<ull, 12> val;
    Tag(){
        for(int i = 0; i < 12; i++)val[i] = 0;
        val[0] = val[8] = val[10] = 1;
    }
	void apply(Tag t){
		array<ull, 12> tt;
		tt[0] = val[0] * t.val[0];
        tt[4] = val[0] * t.val[4] + val[4];
        tt[1] = val[1] * t.val[0] + val[8] * t.val[1];
        tt[5] = val[1] * t.val[4] + val[5] + val[8] * t.val[5];
        tt[8] = val[8] * t.val[8];
        tt[2] = val[2] * t.val[0] + val[10] * t.val[2];
        tt[6] = val[2] * t.val[4] + val[6] + val[10] * t.val[6];
        tt[10] = val[10] * t.val[10];
        tt[3] = val[3] * t.val[0] + val[9] * t.val[1] + val[11] * t.val[2] + val[12] * t.val[3];
        tt[7] = val[3] * t.val[4] + val[7] + val[9] * t.val[5] + val[11] * t.val[6] + t.val[7];
        tt[9] = val[9] * t.val[8] + t.val[9];
        tt[11] = val[11] * t.val[10] + t.val[11];
        val = tt;
	}
};
struct Info{
	ull sum, hsum, suma, sumb, len;
	void apply(Tag t){
		int _sum = sum * t.val[0] + suma * t.val[1] + sumb * t.val[2] + len * t.val[3];
        int _hsum = sum * t.val[4] + hsum + suma * t.val[5] + sumb * t.val[6] + len * t.val[7];
        int _suma = suma * t.val[8] + len * t.val[9];
        int _sumb = sumb * t.val[10] + len * t.val[11];
        sum = _sum;
        hsum = _hsum;
        suma = _suma;
        sumb = _sumb;
	}
};
Info operator+ (const Info &a, const Info &b){
	Info res  = Info();
	res.sum = a.sum + b.sum;
    res.suma = a.suma + b.suma;
    res.sumb = a.sumb + b.sumb;
    res.hsum = a.hsum + b.hsum;
    res.len = a.len + b.len;
	return res;
}
void solve(){
    int n; cin >> n;
    vector<ull> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> Ra(n + 1), Rb(n + 1);
	vector<int>stk;
	for(int i = n; i >= 1; i--){
		while(!stk.empty() && a[stk.back()] < a[i]){
			stk.pop_back();
		}
		if(stk.empty())Ra[i] = n + 1;
		else Ra[i] = stk.back();
		stk.push_back(i);
	}
	stk.clear();
	for(int i = n; i >= 1; i--){
		while(!stk.empty() && b[stk.back()] < b[i]){
			stk.pop_back();
		}
		if(stk.empty())Rb[i] = n + 1;
		else Rb[i] = stk.back();
		stk.push_back(i);
	}
    // vector res(n + 1, vector<int>(n + 1));
    // for(int i = 1; i <= n; i++){
    //     unsigned long long mx1 = a[i], mx2 = b[i];
    //     for(int j = i; j <= n; j++){
    //         mx1 = max(mx1, a[j]);
    //         mx2 = max(mx2, b[j]);
    //         res[i][j] = mx1 * mx2;
    //     }
    // }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << res[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << endl;ac
	int q; cin >> q;
	vector<ull> ans(q + 1);
	vector op(n + 1, vector<array<int, 4>>());
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		if(r + 1 <= n)op[r + 1].push_back({l, r, -1, i});
		op[l].push_back({l, r, 1, i});
	}
	LazySegmentTree<Info, Tag> tr(n);
    for(int i = 1; i <= n; i++){
        tr.update(i, {0, 0, 0, 0, 1});
    }
    Tag t, a1, ab;
    for(int i = 0; i < 12; i++){
        t.val[i] = ab.val[i] = a1.val[i] = 0;
    }
    t.val[0] = t.val[4] = t.val[8] = t.val[10] = 1;
	for(int i = n; i >= 1; i--){
		int R1 = Ra[i] - 1;
		int R2 = Rb[i] - 1;
		int L = min(R1, R2);
        ab.val[3] = a[i] * b[i];
        ab.val[9] = a[i];
        ab.val[11] = b[i];
        //dbg(i, L);
		tr.rangeUpdate(i, L, ab);
		if(R1 > L){
            a1.val[2] = a[i];
            a1.val[9] = a[i];
            a1.val[10] = 1;
			tr.rangeUpdate(L + 1, R1, a1);
            a1.val[2] = 0;
            a1.val[9] = 0;
            a1.val[10] = 0;
		}
		if(R2 > L){
            a1.val[1] = b[i];
            a1.val[11] = b[i];
            a1.val[8] = 1;
			tr.rangeUpdate(L + 1, R2, a1);
            a1.val[1] = 0;
            a1.val[11] = 0;
            a1.val[8] = 0;
		}
		tr.rangeUpdate(i, n, t);
		for(auto [l, r, ty, id] : op[i]){
			ans[id] += ty * tr.rangeQuery(l, r).hsum;
            //dbg(id, l, r, ans[id]);
		}
        if(i == 22){
            dbg(a[i] * b[i], L);
            dbg(tr.rangeQuery(22, 22).sum);
        }
        // cout << i << "____" << tr.rangeQuery(5, 5).sum << endl;
        // cout << i << "____" << tr.rangeQuery(5, 5).hsum << endl;
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    t = 1;
    while(t--)solve();
    return 0;
}