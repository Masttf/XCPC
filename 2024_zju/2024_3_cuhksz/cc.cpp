#include<bits/stdc++.h>
//#define int long long
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
	vector<int>pre(n+5);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+vis[i];
	}
	long long res=0;
	for(int i=1;i<=n;i++){
		res+=(i^p);
	}
	for(int j=1;j<=n;j++){
		long long ans=res;
		for(int i=j+1;i<=n;i+=j+1){
			int t=i-1;
			if(!vis[t]){
				int l=i,r=n+1;
				while(l<=r){
					int mid=(l+r)>>1;
					if(pre[mid]-pre[i-1]==(mid-i+1)){
						t=mid;
						l=mid+1;
					}else r=mid-1;
				}
			}
			
			t++;
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