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
	int n,m,p,b;cin>>n>>m>>p>>b;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i];
	vector<int>vis(n+5);
	for(int i=1;i<=m;i++){
		vis[a[i]]=1;
	}
	vector<int>nt(n+5);
	nt[n+1]=n+1;
	for(int i=n;i>=1;i--){
		nt[i]=nt[i+1];
		if(vis[i]==0)nt[i]=i;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		res+=(i^p);
	}
	for(int j=1;j<=n;j++){
		int ans=res;
		for(int i=j+1;i<=n;i+=j+1){
			int t=nt[i];
			if(t>n)break;
			ans-=(t^p);
			ans+=(t^b);
			i=t;
		}
		cout<<ans<<' ';
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
/*sg
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

	map<int,int>mm;
	// int n,m,p,b;cin>>n>>m>>p>>b;
	// vector<int>a(m+1);
	// for(int i=1;i<=m;i++){
	// 	cin>>a[i];
	// 	mm[a[i]]=1;
	// }
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		mm[x]=1;
	}
	auto dfs = [&](auto self,int now,int y)->int{
		if(now==0)return 0;
		if(mm.count(now))return mm[now];
		int cnt=0;
		int sz=0;
		for(int i=1;i<=min(now,y);i++){
			cnt++;
			sz+=self(self,now-i,y);
		}
		if(cnt==sz)return mm[now]=0;
		else return mm[now]=1;
	};
	for(int i=1;i<=100;i++){
		dbg(i,dfs(dfs,i,5));
	}
	// for(int j=1;j<=n;j++){
	// 	mm.clear();
	// 	int ans=0;
	// 	for(int i=1;i<=m;i++)mm[a[i]]=1;
	// 	for(int i=1;i<=n;i++){
	// 		if(dfs(dfs,i,j)==1)ans+=i^p;
	// 		else ans+=i^b;
	// 	}
	// 	cout<<ans<<' ';
	// }
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
*/