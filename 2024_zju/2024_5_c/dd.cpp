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
constexpr long long Max=1e18;
constexpr int maxn=3e5+5;
int a[maxn],res[maxn];
long long d[maxn],pre[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1],pre[i]=0;
	int s=1;
	while(s<=n&&a[s]==0)s++;
	if(s>=n){
		cout<<0<<'\n';
		return ;
	}
	// auto pf() = [&](__int128 x)->void{
	// 	vector<int>temp;
	// 	while(x){
	// 		temp.push_back()
	// 	}
	// }
	int sz=0;
	int flag=0;
	if(a[s]<0)flag=1;
	int ok=0;
	for(int i=s;i<n;i++){
		//dbg(i);
		pre[i]=pre[i-1]+d[i];
		pre[i+1]=pre[i]+d[i+1];
		int u=pre[i],v=pre[i+1];
		if(u!=1){
			dbg(i,u,v);
		}
		//dbg(i,u,v);
		//assert(u<=Max);
		if(u>Max){
			ok=1;
			break;
		}
		if(flag){
			if(u>=v)continue;
			else{
				while(v>u){
					//pre[i+1]+=u;
					d[i+1]+=u;
					res[sz++]=i;
					v+=u;
				}
			}
		}else{
			if(u<=v)continue;
			else{
				while(v<u){
					d[i+1]+=u;
					//pre[i+1]+=u;
					res[sz++]=i;
					v+=u;
				}
			}
		}
	}
	if(ok)cout<<-1<<'\n';
	else{
		cout<<sz<<'\n';
		for(int i=0;i<sz;i++){
			cout<<res[i]<<" \n"[i==sz-1];
		}
	}

	// for(int i=1;i<=n;i++){
	// 	cout<<pre[i]<<' ';
	// }
	// cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}