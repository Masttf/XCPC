#include<bits/stdc++.h>
//#define int long long
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
template<const int M, class T>
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
		for(int i = 0 ; i < row; i++){
			for(int j = 0; j < col; j++){
				m[i][j] = 0;
			}
		}
	}
	Matrix(vector<vector<T>> &a){
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
using matrix = Matrix<5, unsigned long long>;
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
	matrix tag;
	Tag() : tag(5) {}
	Tag(matrix tag_) : tag(tag_){}
	void apply(Tag t){
		tag = tag * t.tag;
	}
};
struct Info{
	matrix info;
	Info() : info(1, 5){}
	Info(matrix info_) : info(info_){}
	void apply(Tag t){
		info = info * t.tag;
	}
};
Info operator+ (const Info &a, const Info &b){
	Info res  = Info();
	for(int i = 0; i < 5; i++){
		res.info.m[0][i] = a.info.m[0][i] + b.info.m[0][i];
	}
	return res;
}
void solve(){
    int n; cin >> n;
    vector<unsigned long long> a(n + 1), b(n + 1);
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
	int q; cin >> q;
	vector<unsigned long long> ans(q + 1);
	vector op(n + 1, vector<array<int, 4>>());
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		if(r + 1 <= n)op[r + 1].push_back({l, r, -1, i});
		op[l].push_back({l, r, 1, i});
	}
	
	matrix a1(5, 5);
	a1.m[1][1] = 1; a1.m[4][4] = 1;
	matrix ab(5, 5);
	ab.m[1][1] = 1; ab.m[4][4] = 1;
	matrix t(5);
	t.m[0][1] = 1;
	
	vector<Info> temp(n + 1);
	for(int i = 1; i <= n; i++){
		temp[i] = Info();
		temp[i].info.m[0][4] = 1;
	}
	LazySegmentTree<Info, Tag> tr(temp);
	for(int i = n; i >= 1; i--){
		int R1 = Ra[i] - 1;
		int R2 = Rb[i] - 1;
		int L = min(R1, R2);
		ab.m[4][0] = a[i] * b[i];
		ab.m[4][2] = a[i];
		ab.m[4][3] = b[i];
		tr.rangeUpdate(i, L, Tag(ab));
		if(R1 > L){
			a1.m[3][0] = a[i];
			a1.m[4][2] = a[i];
			a1.m[3][3] = 1;
			tr.rangeUpdate(L + 1, R1, Tag(a1));
			a1.m[3][0] = 0;
			a1.m[4][2] = 0;
			a1.m[3][3] = 0;
		}
		if(R2 > L){
			a1.m[2][0] = b[i];
			a1.m[4][3] = b[i];
			a1.m[2][2] = 1;
			tr.rangeUpdate(L + 1, R2, Tag(a1));
			a1.m[2][0] = 0;
			a1.m[4][3] = 0;
			a1.m[2][2] = 0;
		}
		tr.rangeUpdate(i, n, Tag(t));
		for(auto [l, r, ty, id] : op[i]){
			ans[id] += ty * tr.rangeQuery(l, r).info.m[0][1];
		}
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