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
const int mod=998244353;
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
	int n,m;cin>>n>>m;
	vector<pair<int,int>>a(m+1);
	vector<int>p;
	for(int i=1;i<=m;i++){
		cin>>a[i].first>>a[i].second;
		p.push_back(a[i].first);
		p.push_back(a[i].first-1);
		p.push_back(a[i].second);
		p.push_back(a[i].second-1);
	}
	p.push_back(0);
	p.push_back(n);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	int sz=p.size();
	for(int i=1;i<=m;i++){
		a[i].first=get(a[i].first);
		a[i].second=get(a[i].second);
	}
	sort(a.begin()+1,a.end());
	//dbg(sz);
	// for(int i=1;i<=m;i++){
	// 	dbg(a[i].first,a[i].second);
	// }
	vector dp(m+1,vector(sz+1,vector<int>(sz+1)));
	dp[0][get(0)][get(0)]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=sz;j++){
			for(int k=0;k<=sz;k++){
				dp[i][j][k]=dp[i-1][j][k];
			}
		}
		for(int j=a[i].first-1;j<=sz;j++){
			for(int k=j;k<=sz;k++){
				dp[i][max(j,min(k,a[i].second))][max(k,a[i].second)]+=dp[i-1][j][k];
				dp[i][max(j,min(k,a[i].second))][max(k,a[i].second)]%=mod;
			}
		}
	}
	cout<<dp[m][sz][sz]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}