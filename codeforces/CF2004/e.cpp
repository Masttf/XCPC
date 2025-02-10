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
constexpr int maxn = 1e7 + 5;
bool vis[maxn];
vector<int>prim;
int d[maxn];
void init(){
	vector<int>div(maxn);
	for(int i = 2; i < maxn; i++){
		if(!vis[i])prim.push_back(i), div[i] = i;
		for(int j = 0; prim[j] * i < maxn; j++){
			vis[i * prim[j]] = 1;
			div[i * prim[j]] = prim[j];
			if(i % prim[j] == 0)break;
		}
	}
	for(int i = 2; i < maxn; i++){
		d[i] = d[i / div[i]] + 1;
	}
}
void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	if(!vis[x])ans ^= 1;
    }
    if(ans == 0)cout << "Bob\n";
    else cout << "Alice\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}