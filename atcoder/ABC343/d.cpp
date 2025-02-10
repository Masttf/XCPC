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
	int n,m;cin>>n>>m;
	map<int,int>res;
	vector<int>a(n+1,0);
	res[0]=n;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		res[a[x]]--;
		if(res[a[x]]==0)res.erase(a[x]);
		a[x]+=y;
		res[a[x]]++;
		cout<<res.size()<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}