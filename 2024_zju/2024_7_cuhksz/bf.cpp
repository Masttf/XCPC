#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
struct node{
	int u,v,w;
	bool operator <(const node &y)const{
		return w<y.w;
	}
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	auto get = [&](int x)->int{
		int cnt=0;
		while(x){
			cnt++;
			x-=lowbit(x);
		}
		return cnt;
	};
	vector<node>e;
	vector<int>f(n+1);
	for(int i=1;i<=n;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	// auto merge = [&](int a,int b)->void{
	// 	int fa=find(find,a);
	// 	int fb=find(find,b);
	// 	if(fa==fb)return ;
	// 	f[fa]=fb;
	// };
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e.push_back({i,j,get(a[i]^a[j])});
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		dbg(i,j,get(a[i]^a[j]));
	// 	}
	// }
	sort(e.begin(),e.end());
	int sz=n;
	int ans=0;
	for(auto [u,v,w]:e){
		if(sz==1)break;
		int fa=find(find,u);
		int fb=find(find,v);
		if(fa!=fb){
			dbg(a[u],a[v],w);
			sz--;
			f[fa]=fb;
			ans+=w;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}