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
const int Max=1e18;
const int mod=1e9+7;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector g1(n+1,vector<int>());
	vector g2(m+1,vector<int>());
	for(int i=1;i<=k;i++){
		int u,v;cin>>u>>v;
		g1[u].push_back(v);
		g2[v].push_back(u);
	}
	auto get = [&]()->int{
		int ans=0;
		for(int i=1;i<=n;i++){
			int p=1;
			for(auto x:g1[i]){
				int sz=g2[x].size();
				//dbg(i,x,sz);
				p=p*(sz-1)%mod*qmi(sz,mod-2)%mod;
			}
			//dbg(i,p);
			ans+=(1+mod-p)%mod;
			ans%=mod;
		}
		return ans;
	};
	int res1=get();
	swap(g1,g2);
	swap(n,m);
	int res2=get();
	cout<<"modint\n";
	cout<<res1<<' '<<res2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}