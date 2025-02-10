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
int dp[20][200][200][2][2];
void solve(){
	int n,m;cin>>n>>m;
	auto get = [&](int x)->int{
		vector<int>a;
		while(x){
			a.push_back(x%10);
			x/=10;
		}
		reverse(a.begin(),a.end());
		int len=a.size();
		int mod=1;
		auto dfs = [&](auto self,int pos,int st,int now,int limit,int lead)->int{
			if(pos==len){
				if(st==mod&&now==0)return 1;
				else return 0;
			}
			if(dp[pos][st][now][limit][lead]!=-1)return dp[pos][st][now][limit][lead];
			int res=0;
			int mx=(limit?a[pos]:9);
			for(int i=0;i<=mx;i++){
				if(!i&&lead)res+=self(self,pos+1,st,now,limit&&(i==mx),1);
				else res+=self(self,pos+1,st+i,(now*10+i)%mod,limit&&(i==mx),0);
			}
			return dp[pos][st][now][limit][lead]=res;
		};
		int ans=0;
		for(mod=1;mod<=9*len;mod++){
			memset(dp,-1,sizeof(dp));
			ans+=dfs(dfs,0,0,0,1,1);
		}
		return ans;
	};
	int ans1=get(m);
	int ans2=get(n-1);
	cout<<ans1-ans2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}