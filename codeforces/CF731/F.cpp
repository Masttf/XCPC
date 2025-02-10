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
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	vector<int>cnt(mx+1),pre(mx+1);
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	for(int i=1;i<=mx;i++)pre[i]=pre[i-1]+cnt[i];
	int ans=0;
	for(int i=1;i<=mx;i++){
		if(!cnt[i])continue;
		int res=0;
		int last=i;
		while(last<=mx){
			int j=last+i-1;
			if(j>mx)j=mx;
			res+=last*(pre[j]-pre[last-1]);
			//dbg(last,j,res);
			last+=i;
		}
		
		//dbg(i,res);
		ans=max(ans,res);
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