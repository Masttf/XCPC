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
	int n,k;cin>>n>>k;
	int mx=0;
	vector<int>a(n+1);
	map<int,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		k-=a[i];
		m[a[i]]=1;
	}
	vector<int>ans(n+1);
	ans[1]=mx;
	for(int i=2;i<=n;i++){
		if(k==0)break;
		if(k>=mx){
			ans[i]=mx;
			k-=mx;
		}else{
			ans[i]=k;
			if(m.count(k)){
				ans[i+1]=k;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}