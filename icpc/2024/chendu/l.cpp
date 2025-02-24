#include<bits/stdc++.h>
// #define int long long
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
constexpr int Maxn = 4e7 + 5;
using ll = long long;
struct node{
	int lson, rson;
	long long val;
}tr[maxn];
int father[maxn];
void solve(){
    int n; cin >> n;
    vector<array<int, 3>> op(n + 1);
    ll L = 0, R = 1e15;
    vector<int> val(n + 1);
    vector<int> root(n + 5);
    map<long long, int> mp;
    int tot = 0;
    int rt = n + 1;
    int useless = n + 2;
    int id = 0;
    auto newNode = [&](ll l, ll r, int f) -> int{
    	tr[++tot].val = r - l + 1;
    	father[tot] = f;
    	return tot;
    };
    auto up = [&](int p, int l, int r) -> void{
    	
    };
    auto update = [&](auto self, ll l, ll r, ll x, int &p, int f) -> void{
    	if(!p) p = newNode(l, r, f);
    	if(l == r){
    		mp[x] = p;
    		return ;
    	}
    	ll mid = (l + r) >> 1;
    	if(x <= mid)self(self, l, mid, x, tr[p].lson, p);
    	else self(self, mid + 1, r, x, tr[p].rson, p);
    };
    
    auto split = [&](auto self, ll l, ll r, int x, int &u, int &v) -> void{
    	if(l == r){
    		v = u;
    		u = useless;
    		return ;
    	}
    	int mid = (l + r) >> 1;
    	v = ++tot;
 		if(!tr[u].lson) tr[u].lson = newNode(l, r, u);
 		int val = tr[tr[u].lson].val;
 		if(x <= val){
 			self(self, l, mid, x, tr[u].lson, tr[v].lson);
 		}else{

 		}
    };
    for(int i = 1; i <= n; i++){
    	int x, y; cin >> x >> y;
    	op[i] = {x, y};
    	if(x == 3){
    		update(update, L, R, y, root[rt]);
    	}
    }

    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
值域很大怎么做？
动态开点 1e15， 有办法缩点嘛？
*/