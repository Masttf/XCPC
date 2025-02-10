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

std::map<std::string, int> mp;
void solve(){
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 1);
	std::vector<std::vector<std::pair<int, int>>> v(k);
	std::vector<std::string> name(k);
	for(int i = 1; i <= n; ++i) std::cin >> a[i];
	for(int i = 0; i < k; ++i) {
		std::cin >> name[i];
		int num;
		std::cin >> num;
		for(int j = 1; j <= num; ++j) {
			std::pair<int, int> p;
			std::cin >> p.first >> p.second;
			v[i].push_back(p);
		}
	}
	std::unordered_set<int> list;
	for(int i = 1; i <= n; ++i) list.insert(i);
	std::vector<int> ans;
	std::vector<bool> vis(k + 1);
	while(!list.empty()) {
		bool ok = 0;
		for(int i = 0; i < k; ++i) {
			if(vis[i]) continue;
			for(auto [j1, j2]:v[i]) if(list.count(j1) and a[j1] != j2) goto A;
			for(auto [j1, j2]:v[i]) if(list.count(j1)) list.erase(j1);
			ans.push_back(i);
			vis[i] = 1;
			ok = 1;
			if(list.empty()) goto B;
			A:;
		}
		if(!ok) {
			for(auto I:list) {
				if(a[I] != 0) {
					std::cout << "IMPOSSIBLE\n";
					return ;
				}
			}
			break;
			
		}
	}
	B:;
	std::reverse(ans.begin(), ans.end());
	for(auto i:ans) std::cout << name[i] << ' ';


	std::vector<int> pa(n + 1);
	for(auto i:ans) {
		for(auto [j1,j2]:v[i]) {
			pa[j1] = j2;
		}
	}
	for(int i = 1; i <= n; ++i) assert(a[i] == pa[i]);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}