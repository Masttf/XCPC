#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
constexpr int N = 3e5 + 8;
int s[N];
struct node{
	int len, fail, son[26], siz;
	void init(int _len){
		memset(son, 0, sizeof(son));
		fail = siz = 0;
		len = _len;
	}
}tree[N];
int num, last[2], ans, L, R, n, limit, flag;
void init(){
	last[0] = last[1] = 0;
	ans = 0;
	num = 1;
	L = 1e5 + 8, R = 1e5 + 7;
	tree[0].init(0);
	memset(s, -1, sizeof(s));
	tree[1].init(-1);
	tree[0].fail = 1;
}
int getfail(int p, int d){
	if(d){
		while(s[R - tree[p].len - 1] != s[R]){
			p = tree[p].fail;
		}
	}else{
		while(s[L + tree[p].len + 1] != s[L]){
			p = tree[p].fail;
		}
	}
	return p;
}
void Insert(int x, int d){
	if(d) s[++R] = x;
	else s[--L] = x;
	int father = getfail(last[d], d);
	int now = tree[father].son[x];

	if(!now && tree[father].len + 2 <= n){
		now = ++num;
		tree[now].init(tree[father].len + 2);
		tree[now].fail = tree[getfail(tree[father].fail, d)].son[x];
		tree[now].siz = tree[tree[now].fail].siz + 1;
		tree[father].son[x] = now;
	}
	last[d] = now;
	if(R - L + 1 == tree[now].len) last[d ^ 1] = now;
	if(flag){
		if(now > limit){
			dbg(x, tree[now].siz, tree[now].len);
			ans += tree[now].siz;
		}
	}else ans += tree[now].siz;
	
}
void solve(){
	init();
    cin >> n;
    string s; cin >> s;
    for(auto x : s){
    	Insert(x - '0', 1);
    	dbg(x, ans, num - 1);
    }
    limit = num;
    flag = 1;
    for(auto x : s){
    	Insert(x - '0', 1);
    	dbg(x, ans, num - 1);
    }
    dbg(ans);
    dbg(num - 1);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}