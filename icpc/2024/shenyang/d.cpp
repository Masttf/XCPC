#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	vector<int> val(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		val[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] = val[b[i]];
		// dbg(b[i]);
	}
	vector<int> tr(n + 1);
	auto add = [&](int x) -> void{
		while(x <= n){
			tr[x]++;
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
	int sum = 0;
	for(int i = n; i >= 1; i--){
		sum += ask(b[i]);
		add(b[i]);
	}
	// dbg("????");
	// dbg(sum);
	sum %= 2;
	if(sum == 0){
		cout << "B";
	}else cout << "A";
	for(int i = 1; i < n; i++){
		char ty;
		int l, r, d; cin >> ty >> l >> r >> d;
		if((r - l + 1) % 2 == 0){
			d %= 2;
			sum ^= d;
		}
		// dbg(d, r, l, cnt);
		// sum ^= cnt;
		if(sum == 0){
			cout << "B";
		}else cout << "A";
	}
	cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}