#include<bits/stdc++.h>
#define int long long
using namespace std;
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
struct trie{
	struct node{
		int l, r;
	};
	int tot;
	vector<node>tr;
	vector<array<int, 3>> tag;
	int Max = (1ll << 31) - 1;
	trie(int n){
		tot = 1;
		tr.assign(n, {0, 0});
		tag.assign(n, {0, 0, 0});
	}
	void cg(int p, array<int, 3> val){
		tag[p][0] |= val[0];
		tag[p][1] -= tag[p][1] & val[0];
		tag[p][1] ^= val[1]; 
	}
	void down(int p, int dep){
		if((tag[p][0] >> dep) & 1){
			merge(tr[p].r, tr[p].l, dep - 1);
		}
		if((tag[p][0] >> dep) & 1){
			merge(tr[p].l, tr[p].r, dep - 1);
		}
		if((tag[p][2] >> dep) & 1){
			swap(tr[p].l, tr[p].r);
		}
		if(tr[p].l)cg(tr[p].l, tag[p]);
		if(tr[p].r)cg(tr[p].r, tag[p]);
		tag[p] = {0, 0, 0};
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


void solve(){
	int n, m; cin >> n >> m;
	trie t((n + m) * 32);
	
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		t.insert(x);
	}
	for(int i = 1; i <= m; i++){
		int op, a; cin >> op >> a;
		if(op == 1)t.insert(a);
		else if(op == 2){
			t.cg(1, {a, 0});
		}else if(op == 3){
			t.cg(1, {0, t.Max});
			t.cg(1, {a ^ t.Max, 0});
			t.cg(1, {0, t.Max});
		}else if(op == 4){
			t.cg(1, {0, a});
		}else{
			cout << t.query(a) << '\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}