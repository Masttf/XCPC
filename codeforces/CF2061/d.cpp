#include<bits/stdc++.h>
#define int long long
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
void solve(){
    int n, m; cin >> n >> m;
    map<int, int> a;
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	a[x]++;
    }
    int ok = 1;
    auto dfs = [&](auto self, int x) -> void{
    	if(ok == 0)return ;
    	if(a.count(x)){
    		a[x]--;
    		if(a[x] == 0)a.erase(x);
    		return ;
    	}
    	if(x == 1){
    		ok = 0;
    		return ;
    	}
    	if(x % 2 == 0){
    		self(self, x / 2);
    		if(ok == 0)return ;
    		self(self, x / 2);
    		if(ok == 0)return ;
    	}else{
    		self(self, x / 2);
    		if(ok == 0)return ;
    		self(self, x / 2 + 1);
    		if(ok == 0)return ;
    	}
    	return ;
    };
    for(int i = 1; i <= m; i++){
    	int x; cin >> x;
    	if(a.count(x)){
    		a[x]--;
    		if(a[x] == 0)a.erase(x);
    	}else{
    		dfs(dfs, x);
    	}
    }
    if(ok && a.empty())cout << "Yes\n";
    else cout << "No\n";
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
/*
如果原先就有不要动
那么现在
a 数组和 b数组 都不相同

由偶数个数组合而来
如果是偶数 那么就是两个相同的合成而来
否则就是
*/