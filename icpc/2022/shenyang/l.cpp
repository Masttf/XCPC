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
void solve(){
    vector<int>lim(3);
    for(int i = 0; i < 2; i++) cin >> lim[i];
    vector a(3, vector<int>(10));
    vector h(3, vector<int>(10));
    for(int i = 0; i < lim[0]; i++) cin >> a[0][i], h[0][i] = a[0][i];
    for(int i = 0; i < lim[1]; i++) cin >> a[1][i], h[1][i] = a[1][i];
    vector<double> ans(5);
	vector alive(3, vector<int> (10));
	vector cnt(3, vector<int> (10));

    auto dfs = [&](auto self, int now, double p) -> void{
    	int c[2] = {};
    	for(int j = 0; j < 2; j++){
    		for(int i = 0; i < lim[j]; i++){
    			if(alive[j][i] == 1)c[j]++;
    		}
    	}
    	if(c[0] == lim[0] && c[1] == lim[1]){
    		ans[2] += p;
    		return ;
    	}
    	if(c[0] == lim[0]){
    		ans[1] += p;
    		return ;
    	}
    	if(c[1] == lim[1]){
    		ans[0] += p;
    		return ;
    	}
    	int chose = 0;
    	int mi = 1e9;
    	for(int i = 0; i < lim[now]; i++){
    		if(alive[now][i] == 0) mi = min(mi, cnt[now][i]);
    	}
    	for(int i = 0; i < lim[now]; i++){
    		if(alive[now][i] == 0 && cnt[now][i] == mi){
    			chose = i;
    			break;
    		}
    	}
    	cnt[now][chose]++;
    	//dbg(now, chose, c[0], c[1]);
    	for(int i = 0; i < lim[now ^ 1]; i++){
    		if(alive[now ^ 1][i] == 0){
    			h[now][chose] -= a[now ^ 1][i];
    			h[now ^ 1][i] -= a[now][chose];
    			if(h[now][chose] <= 0){
    				alive[now][chose] = 1;
    			}
    			if(h[now ^ 1][i] <= 0){
    				alive[now ^ 1][i] = 1;
    			}
    			self(self, now ^ 1, p * (1.0 / (lim[now ^ 1] - c[now ^ 1])));
    			h[now][chose] += a[now ^ 1][i];
    			h[now ^ 1][i] += a[now][chose];
    			if(h[now][chose] > 0){
    				alive[now][chose] = 0;
    			}
    			if(h[now ^ 1][i] > 0){
    				alive[now ^ 1][i] = 0;
    			}
    		}
    	}
    	cnt[now][chose]--;
    };
    if(lim[0] > lim[1]){
    	dfs(dfs, 0, 1);
    }else if(lim[0] < lim[1]){
    	dfs(dfs, 1, 1);
    }else{
    	dfs(dfs, 0, 0.5);
    	dfs(dfs, 1, 0.5);

    }
    for(int i = 0; i <= 2; i++){
    	cout << fixed << setprecision(10) << ans[i] << ' ';
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}