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
	int n;cin>>n;
	vector<string>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,(int)a[i].size());
		a[i]=' '+a[i];
	}
	vector f(n+1,vector<int>(mx+1));
	vector<int>p(mx+1);
	p[0]=1;
	for(int i=1;i<=mx;i++)p[i]=p[i-1]*131;
	auto hash = [&](int k)->void{
		int len=a[k].size();
		for(int i=1;i<len;i++)f[k][i]=f[k][i-1]*131+a[k][i]-'a'+1;
	};
	auto get = [&](int k,int l,int r)->int{
		return f[k][r]-f[k][l-1]*p[r-l+1];
	};
	for(int i=1;i<=n;i++)hash(i);
	vector<int>res;
	for(int i=1;i<=n;i++){
		int ok=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i]==a[j]){
				if(i<j)continue;
			}
			int len1=a[i].size()-1;
			int len2=a[j].size()-1;
			if(len1>len2)continue;
			
			for(int k=1;k+len1-1<=len2;k++){
				if(ok)break;
				if(get(j,k,k+len1-1)==f[i][len1])ok=1;
			}
			//dbg(i,j,ok);
		}
		if(!ok){
			res.push_back(i);
			//dbg(i);
		}
	}
	auto js = [&](int x,int y)->int{
		int len1=a[x].size()-1;
		int len2=a[y].size()-1;
		int ans=0;
		for(int i=1;i<=min(len1,len2);i++){
			int d1=get(x,len1-i+1,len1);
			int d2=get(y,1,i);
			// dbg(x,y,len1-i+1,len1,1,i);
			// dbg(d1,d2);
			if(d1==d2)ans=i;
		}
		return len2-ans;
	};
	int sz=res.size();
	vector g(sz+1,vector<int>(sz+1));
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			g[i][j]=js(res[i],res[j]);
			//dbg(i,j,g[i][j]);
		}
	}
	vector dp(sz,vector<int>(1<<sz,1e18));
	for(int i=0;i<sz;i++){
		dp[i][1<<i]=a[res[i]].size()-1;
	}
	for(int i=1;i<(1<<sz);i++){
		for(int j=0;j<sz;j++){
			if(i>>j&1){
				for(int k=0;k<sz;k++){
					if(((i^(1<<j))>>k)&1){
						dp[j][i]=min(dp[j][i],dp[k][i^(1<<j)]+g[k][j]);
					}
				}
			}
		}
	}
	int ans=1e18;
	for(int i=0;i<sz;i++)ans=min(ans,dp[i][(1<<sz)-1]);
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