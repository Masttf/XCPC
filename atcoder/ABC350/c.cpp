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
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>pos(n+1);
	for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
	vector<pair<int,int>>res;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			res.push_back({i,pos[i]});
			int temp=a[i];
			swap(a[pos[i]],a[i]);
			swap(pos[i],pos[temp]);
		}
	}
	cout<<res.size()<<'\n';
	for(auto [x,y]:res)cout<<x<<' '<<y<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}