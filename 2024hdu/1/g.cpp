#include<bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x) & -(x))
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
struct node{
	int a, b, c;
};
bool cmp(node x, node y){
	if(x.b != y.b)return x.b < y.b;
	if(x.a != y.a)return x.a < y.a;
	return x.c < y.c;
}
void solve(){
	int n; cin >> n;
	vector<node> q(n + 1);
	vector<int> du(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> q[i].b;
		q[i].a = i;
		du[i] += n - i;
	}
	for(int i = 1; i <= n; i++){
		cin >> q[i].c;
	}
	vector<int>tr(n + 1);
	auto add = [&](int x, int val) -> void{
		while(x <= n){
			tr[x] += val;
			x += lowbit(x);
		}
	};
	auto ask = [&](int x) -> int{
		int res = 0;
		while(x){
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	};
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
		j = r;
		i = mid;
		for(; i >= l; i--){
			while(j >= mid + 1 && q[j].b > q[i].b){
				add(q[j].c, 1);
				j--;
			}
			du[q[i].a] -= ask(n) - ask(q[i].c);
		}
		for(j++; j <= r; j++){
			add(q[j].c, -1);
		}
		sort(q.begin() + l, q.begin() + r + 1, cmp);
	};
	cdq(cdq, 1, n);
	long long ans = 1ll * n * (n - 1) /2 * (n - 2) / 3;
	for(int i = 1; i <= n; i++){
		if(du[i] >= 2){
			ans -= 1ll * du[i] * (du[i] - 1) / 2;
		}
		//dbg(i, du[i]);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}