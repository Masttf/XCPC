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
void solve(){
	int n; cin >> n;
	int N = 1e5;
	vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
	vector<int> vis(N + 1);
	for(int i = 1; i <= n; i++){
        vis[a[i]] = 1;
    }
    vector<int>f(N + 1);
    int cnt = 0;
	for(int i = N; i >= 1; i--){
        int num = 0;
        for(int j = i; j <= N; j += i){
        	if(vis[j])num++;
        }
        f[i] = (num - 1) * num / 2;
        for(int j = 2 * i; j <= N; j += i){
            f[i] -= f[j];
        }
        if(f[i] && !vis[i]){
        	vis[i] = 1;
        	num = 0;
        	for(int j = i; j <= N; j += i){
	        	if(vis[j])num++;
	        }
        	f[i] = (num - 1) * num / 2;
	        for(int j = 2 * i; j <= N; j += i){
	            f[i] -= f[j];
	        }
        	cnt++;
        }
    }
    if(cnt % 2 == 0)cout <<"Haitang\n";
    else cout << "dXqwq\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}