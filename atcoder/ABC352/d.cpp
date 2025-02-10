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
constexpr int Max=1e18;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    vector<int>p(n+1);
    for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
    int ans=Max;
	map<int,int>l;
	map<int,int>r;
	for(int i=1;i<=k;i++){
		l[p[i]]=1;
		r[p[i]]=1;
	}
	ans=min(ans,r.rbegin()->first-l.begin()->first);
	for(int i=k+1;i<=n;i++){
		int d=i-k;
		l.erase(p[d]);
		r.erase(p[d]);
		l[p[i]]=1;
		r[p[i]]=1;
		ans=min(ans,r.rbegin()->first-l.begin()->first);
	}
	cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}