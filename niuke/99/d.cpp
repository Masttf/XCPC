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
constexpr int maxn = 1e7;
bool vis[maxn + 5];
vector<int>prim;
void init(){
	vis[1] = 1;
	for(int i = 2; i <= maxn; i++){
		if(!vis[i])prim.push_back(i);
		for(int j = 0; prim[j] * i <= maxn; j++){
			vis[i * prim[j]] = 1;
			if(i % prim[j] == 0)break;
		}
	}
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    set<int> s;
	for(int i = 1; i <= n; i++)s.insert(a[i]);
	for(auto x : prim){
		if(s.count(x))continue;
		cout << x << '\n';
		break;
	}
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