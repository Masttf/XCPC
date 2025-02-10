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
constexpr int maxn = 11, Max = 1e18;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q[maxn][maxn];
void solve(){
    int n, k; cin >> n >> k;
    vector cost(n + 1, vector<int> (k + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= k; j++){
    		cin >> cost[i][j];
    	}
    }
    vector<int> a(k + 1);
    for(int i = 1; i <= k; i++) cin >> a[i];
    int ans = 0;
    vector<int>bl(n + k + 1);
    for(int i = 1; i <= k; i++){
    	bl[i + n] = i;
    }
    for(int i = 0; i <= k; i++){
    	for(int j = 1; j <= k; j++){
    		if(i == 0)q[i][j].push({Max, 0});
    		else q[i][j].push({Max, i + n});
    	}
    }
    
    auto add = [&](int x) -> void{
    	int s = bl[x];
    	for(int i = 1; i <= k; i++){
    		if(i == s)continue;
    		q[s][i].push({cost[x][i] - cost[x][s], x});
    	}
    };
    for(int i = 1; i <= n; i++)add(i);
    int tot = n;
    while(tot--){
    	int mx = 2e9;
    	pair<int, int> op = {0, 0};
    	for(int i = 0; i <= k; i++){
    		for(int j = 1; j <= k; j++){
    			while(bl[q[i][j].top().second] != i)q[i][j].pop();
    		}
    	}
    	for(int i = 0; i <= k; i++){
    		for(int j = 1; j <= k; j++){
    			if(a[j] == 0)continue;
    			int val = q[i][j].top().first;
				if(i != 0) val += q[0][i].top().first;
				if(val < mx){
					mx = val;
					op = {i, j};
				}
    		}
    	}
    	ans += mx;
    	auto [u, v] = op;
    	a[v]--;
    	assert(v != 0);
    	//dbg(u, v);
    	if(u == 0){
    		int x = q[u][v].top().second;
    		q[u][v].pop();
    		bl[x] = v;
    		add(x);
    	}else{
    		int x = q[0][u].top().second;
    		int y = q[u][v].top().second;
    		q[0][u].pop();
    		q[u][v].pop();
    		bl[x] = u;
    		bl[y] = v;
    		add(x);
    		add(y);
    	}
    }
    // for(int i = 1; i <= n; i++){
    // 	dbg(i, bl[i]);
    // }
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