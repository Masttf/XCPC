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
int dp[20][20][2][2];
int a[20];
void solve(){
	int x,y;cin>>x>>y;
	int len,v;
	auto dfs = [&](auto self,int pos,int st,int limit,int lead)->int{
		if(pos>len)return st;
		if(dp[pos][st][limit][lead]!=-1)return dp[pos][st][limit][lead];
		int res=0;
		int mx=(limit?a[pos]:9);
		for(int i=0;i<=mx;i++){
			if(!i&&lead)res+=self(self,pos+1,st,limit&&(i==a[pos]),1);
			else{
				res+=self(self,pos+1,st+(i==v),limit&&(i==a[pos]),0);
			}
		}
		return dp[pos][st][limit][lead]=res;
	};
	for(int i=0;i<=9;i++){
		v=i;
		int temp=y;
		len=0;
		while(temp){
			a[++len]=temp%10;
			temp/=10;
		}
		for(int j=1;j<=len/2;j++)swap(a[j],a[len-j+1]);
		
		memset(dp,-1,sizeof(dp));
		int d1=dfs(dfs,1,0,1,1);
		memset(a,0,sizeof(a));
		temp=x-1;
		len=0;
		while(temp){
			a[++len]=temp%10;
			temp/=10;
		}
		for(int j=1;j<=len/2;j++)swap(a[j],a[len-j+1]);
		memset(dp,-1,sizeof(dp));
		int d2=dfs(dfs,1,0,1,1);
		memset(a,0,sizeof(a));
		cout<<d1-d2<<' ';//不用考虑0，一定会减掉
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