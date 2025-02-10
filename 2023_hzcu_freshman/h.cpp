#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>st(n+1);
	vector<int>ed(n+1);
	for(int i=1;i<=n;i++){
		if(!st[a[i]])st[a[i]]=i;
		ed[a[i]]=i;
	}
	vector<int>p1(n+1),p2(n+1);
	for(int i=1;i<=m;i++){
		p1[st[i]]=ed[i];
		p2[ed[i]]=st[i];
	}
	vector<int>t(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			t[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	int ok=1;
	for(int i=1;i<=n;i++){
		if(p1[i]){
			updata(i,1);
			updata(p1[i]+1,-1);
		}
		if(p2[i]){
			int d=ask(i)-ask(p2[i]);		
			if(d!=0){
				ok=0;
				break;
			}
		}
	}
	if(!ok){
		cout<<"NO\n";
		return ;
	}
	vector<int>ans;
	vector<int>vis(m+1);
	for(int i=1;i<=n;i++){
		if(!vis[a[i]]){
			ans.push_back(a[i]);
			vis[a[i]]=1;
		}
	}
	cout<<"YES\n";
	for(auto x:ans)cout<<x<<' ';
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
