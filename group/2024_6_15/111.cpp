#include<bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
using Pii = std::pair<int, int>;
Pii dec(Pii a, Pii b) { return {a.first - b.first, a.second - b.second}; }
Pii add(Pii a, Pii b) { return {a.first + b.first, a.second + b.second}; }
i128 dis_2(Pii a, Pii b) { return (i128)(a.first - b.first) * (a.first - b.first) + (i128)(a.second - b.second) * (a.second - b.second); }
bool Ch(Pii a, Pii b) { return (a.first * b.first + a.second * b.second) == 0; }
int cross(Pii a, Pii b) { return ((i128)a.first*b.second - (i128)a.second*b.first) % (int)(1e9 + 7); }
void solve(){
	int n;
	std::cin >> n;
	vector<Pii> v(n);
	std::map<Pii, int> s;
	for(int i = 0; i < n; ++i) std::cin >> v[i].first >> v[i].second, s[v[i]] = i;
	// int ans = 0;
	std::set<vector<int>>ans;
	std::map<Pii, vector<Pii>> X;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int x = v[j].second - v[i].second;
			int y = v[j].first - v[i].first;
			int k = __gcd(x, y);
			assert(k != 0);
			
			x /= k;
			y /= k; 
			if(x < 0) x = -x, y = -y;
			X[{x, y}].push_back({i, j});
			// X[{x, y}].push_back({j, i});
		}
	}
	// std::cout << "---------" << std::endl;
	auto ins = [&](vector<int>a) ->void {
		std::sort(a.begin(), a.end());
		a.erase(std::unique(a.begin(), a.end()), a.end());
		if(a.size() == 5) ans.insert(a);
	};
	auto check = [&](int i, int j, int k)->void {
		// std::cout << std::format("{} {} {}\n", i, j, k);
		if(dis_2(v[i], v[k]) != dis_2(v[j], v[k])) return ;
		int x = v[j].second - v[i].second;
		int y = v[j].first - v[i].first;
		int K = __gcd(x, y);
		x /= K, y /= K;
		if(x < 0) x = -x, y = -y;
		if(!X.count({x, y})) return ;
		for(auto [x1, x2]:X[{x, y}]) {
			auto p1 = v[x1];
			auto p2 = v[x2];
			if(dis_2(v[k], p1) == dis_2(v[k], p2) and dis_2(p1, p2) == dis_2(v[i], v[j]) and cross(dec(v[i],v[j]),dec(v[i],v[k])) * cross(dec(v[i],v[j]), dec(v[i], p2)) < 0) {
				// std::cout << std::format("{} {} {} {} {}\n", i, j, k, x1, x2);
				ins({i,j,k,x1,x2});
			} 
		}
	};
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) continue;
			for(int k = 0; k < n; ++k) {
				if(i == k or j == k) continue;
				check(i, j, k);
			}
		}
	}
	std::cout << ans.size() << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}