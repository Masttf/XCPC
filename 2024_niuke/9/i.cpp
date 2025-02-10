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
struct std::hash<std::tuple<int, int, int, __int128>> {
	size_t operator()(const std::tuple<int, int, int, __int128> &x) const {
		return std::get<0>(x) ^ std::get<1>(x) ^ std::get<2>(x) ^ (int)(std::get<3>(x) >> 64) ^ (int)(std::get<3>(x));
	}
};
void solve(){
	int n;
	string l, r;
	cin >> n >> l >> r;
	auto get = [&](string x)->int{
        //vector dp(60,vector(10,vector(2,vector<int>(2))));
        unordered_map<std::tuple<int, int, int, __int128>, int>dp;
        vector<int>p;
        for(int i = 0; i < n; i++){
        	p.push_back(x[i] - '0');
        }
        //
        auto check = [&](__int128 x) -> bool{
        	for(int i = 2; i * i <= x; i++){
        		if(x % i == 0)return false;
        	}
        	return true;
        };
        auto dfs = [&](auto self,int now,int last,int limit,int lead, __int128 val) -> int{
            if(now == -1){
            	if(check(val))return dp[{now, last, limit, val}] = 1;
            	else return dp[{now, last, limit, val}] = 0;
            }
            if(dp.count({now, last, limit, val}))return dp[{now, last, limit, val}];
            int res = 0;
            if(now == n / 2){
            	if(!check(val))return dp[{now, last, limit, val}] = 0;
            	val = 0;
            }
            for(int i = 0; i <= (limit ? p[now] : 9); i++){
                if(lead==1)res+=self(self,now - 1, i , limit && i == p[now], i==0, val * 10 + i);
                else{
                    res+=self(self,now-1,i,limit&&i==p[now],0, val * 10 + i);
                }
            }
            return dp[{now, last, limit, val}] = res;
        };
        return dfs(dfs, p.size() - 1, 0, 1, 1, 0);
    };
    int ans = get(r) - get(l);
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