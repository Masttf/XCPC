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
	int n,k;cin>>n>>k;
	vector<int>a(2*n+1);
	vector<int>p1(n+1),p2(n+1);
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		if(!p1[a[i]])p1[a[i]]=i;
		else p2[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(p1[i]>p2[i])swap(p1[i],p2[i]);
	}
	vector<int>b,c;
	vector<int>vis(2*n+1);
	for(int i=1;i<=n;i++){
		if(b.size()==2*k)break;
		if(vis[i])continue;
		if(p2[a[i]]<=n){
			b.push_back(a[i]);
			b.push_back(a[i]);
			vis[p1[a[i]]]=1;
			vis[p2[a[i]]]=1;
		}
	}
	for(int i=n+1;i<=2*n;i++){
		if(c.size()==2*k)break;
		if(vis[i])continue;
		if(p1[a[i]]>n){
			c.push_back(a[i]);
			c.push_back(a[i]);
			vis[p1[a[i]]]=1;
			vis[p2[a[i]]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(b.size()==2*k)break;
		if(vis[i])continue;
		if(p2[a[i]]>n){
			b.push_back(a[i]);
			c.push_back(a[i]);
		}
	}
	for(auto x:b)cout<<x<<' ';
	cout<<'\n';
	for(auto x:c)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}