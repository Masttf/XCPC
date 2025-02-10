#include<bits/stdc++.h>
#define ll long long
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
constexpr int N=1e6;
constexpr ll Max=1e18;
map<ll,int> val[N+1];
ll f[N+1];
ll mx[N+1];
int sz[N+1];
void solve(){
	for(int i=1;i<=N;i++){
		mx[i]=-Max;
		f[i]=-Max;
		val[i][-Max]++;
	}
	int n;cin>>n;
	map<ll,int>ans;
	ans[-Max]=N;
	auto up = [&](int x)->void{
		while(x>=1){
			auto it = ans.find(f[x]);
			--it->second;
			if(it->second==0){
				ans.erase(it);
			}
			f[x]=mx[x];
			if(2*x<=N&&sz[x*2])f[x]=max(f[x],f[2*x]+mx[x]);
			if(2*x+1<=N&&sz[x*2+1])f[x]=max(f[x],f[2*x+1]+mx[x]);
			if(!sz[x])f[x]=-Max;
			ans[f[x]]++;
			x/=2;
		}
	};
	for(int i=1;i<=n;i++){
		int t,d,b;cin>>t>>d>>b;
		if(t==1){
			val[d][b]++;
			sz[d]++;
			mx[d]=val[d].rbegin()->first;
			up(d);
		}else{
			val[d][b]--;
			sz[d]--;
			if(val[d][b]==0)val[d].erase(b);
			mx[d]=val[d].rbegin()->first;
			up(d);
		}
		cout<<max(0ll,ans.rbegin()->first)<<'\n';
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