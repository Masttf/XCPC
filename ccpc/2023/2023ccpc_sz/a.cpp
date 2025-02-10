#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	sort(a.begin()+1,a.end());
	vector<pair<int,int>>ans;

	vector<int>b(n+5);
	vector<int>c(n+5);
	auto dfs = [&](auto self,int l,int r)->void{
		//dbg(l,r);
		for(int i=1;i<=n;i++){
			c[i]+=c[i-1],b[i]+=c[i];
			//cout<<b[i]<<" \n"[i==n];
		}
		for(int i=1;i<=n;i++)c[i]=0;
		if(l==r){
			int d=a[l].first-b[l];
			for(int i=1;i<=d;i++){
				ans.push_back({2,a[l].second});
				b[l]++;
			}
			return ;
		}
		
		int mid=(l+r)>>1;
		int s=b[mid+1];
		if(s<a[mid+1].first){
			for(int i=mid+1;i<=r;i++){
				ans.push_back({2,a[i].second});
				b[i]++;
			}
			s++;
		}
		//dbg(s,mid+1,a[mid+1]);
		while(s<a[mid+1].first){
			ans.push_back({1,s});
			c[mid+1]++;
			c[r+1]--;
			s++;
		}

		self(self,l,mid);
		self(self,mid+1,r);
	};
	dfs(dfs,1,a.size()-1);
	assert(ans.size()<=20000);
	cout<<ans.size()<<'\n';
	for(auto [u,v]:ans)cout<<u<<' '<<v<<'\n';
	// vector<int>temp(n+1);
	// for(auto [u,v]:ans){
	// 	if(u==1){
	// 		for(int i=1;i<=n;i++){
	// 			if(temp[i]==v)temp[i]++;
	// 		}
	// 	}else temp[v]++;
	// }
	// for(int i=1;i<=n;i++)cout<<temp[i]<<' ';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}