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


template<>
struct std::hash<std::tuple<int, int, __int128>> {
	size_t operator()(const std::tuple<int, int, __int128> &x) const {
		return std::get<0>(x) ^ std::get<1>(x) ^ (int)(std::get<2>(x) >> 64) ^ (int)(std::get<2>(x));
	}
};
void solve(){
	int n;
	string l, r;
	cin >> n >> l >> r;
    auto get_mx = [&](__int128 lim) ->__int128{
        __int128 res = 0;
        __int128 l = 0;
        __int128 r = 1e15;
        while(l <= r){
            __int128 mid = (l + r) / 2;
            if(mid * mid > lim){
                r = mid - 1;
            }else{
                res = mid;
                l = mid + 1;
            }
        }
        return res;
    };
    auto check = [&](__int128 x) -> bool{
        __int128 l = get_mx(x);
        return l * l == x;
    };
	auto get = [&](string x)->int{
        map<tuple<int, int, __int128>, int>dp;
        vector<int>p;
        for(int i = n - 1; i >= 0; i--){
        	p.push_back(x[i] - '0');
        }
        auto dfs = [&](auto self, int now, int limit, __int128 val) -> int{
            if(now == -1){
            	if(check(val))return dp[{now, limit, val}] = 1;
            	else return dp[{now, limit, val}] = 0;
            }
            if(now == n / 2 - 1){
                if(!check(val))return dp[{now, limit, val}] = 0;
                val = 0;
            }
            if(dp.count({now, limit, val}))return dp[{now, limit, val}];
            int res = 0;
            for(int i = 0; i <= (limit ? p[now] : 9); i++){
                res += self(self, now - 1, limit && i==p[now], val * 10 + i);
            }
            return dp[{now, limit, val}] = res;
        };
        return dfs(dfs, n - 1, 1, 0);
    };
    int ans = get(r) - get(l);
    __int128 t = 0;
    int ok = 1;
    for(int i = 0; i < n; i++){
        t = t * 10 + l[i] - '0';
        if(i == n / 2 - 1){
            if(!check(t))ok = 0;
            t = 0;
        }
    }
    if(check(t) && ok)ans++;
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