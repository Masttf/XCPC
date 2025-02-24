#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x);\
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
	int a, b;
};
void solve(){
	int n; cin >> n;
	vector<int> c(n + 1);
	vector<node> a(n + 1); 
	for(int i = 1; i <= n; i++){
		cin >> a[i].a;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i].b;
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	sort(c.begin() + 1, c.end());
	vector<node>z, f;
	for(int i = 1; i <= n; i++){
		if(a[i].a >= 0){
			z.push_back(a[i]);
		}else f.push_back(a[i]);
	}
	// dbg("????");
	int num = (n + 1) / 2;
	multiset<int> sz;
	multiset<int> sf;
	int last = 1;
	for(int i = 1; i <= f.size(); i++){
		sf.insert(c[last++]);
	}
	for(int i = last; i <= n; i++){
		sz.insert(c[i]);
	}
	auto check = [&](int limit) -> bool{
		int cnt = 0;
		multiset<int> s1 = sz;
		multiset<int> s2 = sf;
		for(auto [x, y] : z){
			if(x == 0){
				if(y >= limit){
					cnt++;
				}
			}else{
				int d;
				if(limit - y >= 0){
					d = (limit - y + x - 1) / x;
				}else{
					d = -((y - limit) / x);
				}
				auto it = s1.lower_bound(d);
				if(it != s1.end()){
					cnt++;
					s1.erase(it);
				}
			}
		}
		// dbg(cnt);
		for(auto [x, y] : f){
			int d;
			if(limit - y <= 0){
				d = (limit - y) / x;
			}else d = -((limit - y + (-x) - 1) / (-x));

			if(s2.empty())continue;
			auto it = s2.upper_bound(d);
			if(it == s2.begin())continue;
			it--;
			cnt++;
			s2.erase(it);
			
		}
		// dbg(limit, cnt, num);
		return cnt >= num;
	};
	int l = -3e18, r = 3e18;
	int ans = l;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans << '\n';
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